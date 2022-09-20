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
	int fd, n, c;
	fd = open("list.txt", O_RDONLY);


	for(int i=0; i<10; i++){
		c = 0;
		while((n = read(fd, &userID[i][c], 1)) == 1){
			if(userID[i][c] == ' ') { 
				userID[i][c] = '\0'; 
				break;
			}
			c++;
		}
		c = 0;
		while((n = read(fd, &pwdID[i][c], 1)) == 1){
			if(pwdID[i][c] == '\n') { 
				pwdID[i][c] = '\0';
				break;
			}
			c++;
		}
	}
	close(fd);	
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
