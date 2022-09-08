#include "types.h"
#include "stat.h"
#include "user.h"

int numOfLine;
char buf[512];

int _atoi(char* str){
	int sign = 1, data = 0;

	if(*str == '\n') return 0;
	if(*str == '-') sign = -1;

	while(*str >= '0' && *str <= '9'){
			data *= 10;
			data += (*str - '0');
			str++;
	}

	return data*sign;
}

void cat(int fd){
	
	int n, cnt=0;
	while((n = read(fd, buf, 1)) > 0){
		if(write(1, buf, n) != n){
			printf(1,"cat: write error\n");
			exit();
		}

		if(buf[0] == '\n'){
			cnt++;
			if(cnt == numOfLine) break;
		}
	}
	if(n<0){
		printf(1, "cat: read error\n");
		exit();
	}
}

int main(int argc, char *argv[]){
	numOfLine = _atoi(argv[1]);
	int fd, i;
	
	// num of main arguments are not enough
	if(argc <= 1){
		cat(0);
		exit();
	}

	
	for(i=2; i<argc; i++){
		
		// file is null
		if((fd = open(argv[i], 0)) < 0){
			printf(1, "cat: cannot open %s\n", argv[i]);
			exit();
		}
		cat(fd);
		close(fd);
	}
	exit();
}
