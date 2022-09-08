#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char userID[16][32];
char pwdID[16][32];

char inputID[32];
char inputPW[32];


char *l_argv[] = { "sh", 0 };

int _strcmp(char* input, char (*list)[32]){
	
	int i=0;
	while(input[i] != '\n'){
		if(input[i] != *((*list)+i)) return -1;
		i++;
	}

	if(*((*list)+i)!= '\0')
		return -1;
	else 
		return 0;
}

void get_user_list(){
	// file loading
//	int fd;
//	fd = open("list.txt", O_RDONLY);


	userID[1][0] = 'r';
	userID[1][1] = 'o';
	userID[1][2] = 'o';
	userID[1][3] = 't';
	pwdID[1][0] = '1';
	pwdID[1][1] = '2';
	pwdID[1][2] = '3';
	pwdID[1][3] = '4';
	for(int i=0; i<10; i++){
		;
	}
	
}

int check_idpw(){

	for(int i=0;i<10;i++){
		if(!_strcmp(inputID, &userID[i]) && !_strcmp(inputPW, &pwdID[i])) return 1;
	}
	return 0;
}

int main(int argc, char* argv[]){
	
	int pid,wpid;

	for(;;){
	// input Enter included
	printf(1,"Username: ");
	read(0, inputID, sizeof(inputID));

	printf(1, "Password: ");
	read(0, inputPW, sizeof(inputPW));

	get_user_list();

	
	if(check_idpw()){
		pid = fork();

		if(pid < 0){
			printf(1, "init: fork failed\n");
			exit();
		}
		if(pid == 0){
		//	printf(1, "fork success\n");
			exec("sh", l_argv);	
			printf(1, "init: exec sh failed\n");
			exit();
		}

		while((wpid=wait()) >= 0 && wpid != pid)
			printf(1, "zombie!\n");

	}else{
		printf(1, "Username or Password is wrong\n");
	}
	}
	
}
