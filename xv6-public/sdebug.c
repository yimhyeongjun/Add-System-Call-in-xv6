#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define PNUM 5
#define PRINT_CYCLE 10000000
#define TOTAL_COUNTER 500000000

void sdebug_func(){

	int n, pid;
	long long start_time, end_time;

	printf(1,"start sdebug command\n");
	
	for(n=0;n<PNUM;n++){
		pid = fork();
		// counter 증가 시키기
		if(pid < 0){
			printf(1,"fork error\n");
			exit();
		}
		if(pid == 0){
			int counter = 0;
			int first = 1, print_counter = 0;
			start_time = uptime();
			weightset(n+1);	

			for(counter=0;counter<TOTAL_COUNTER; counter++){
				if(counter == PRINT_CYCLE){
					if(print_counter == 0){
						if(first){
							end_time = uptime();
							printf(1,"PID: %d, WEIGHT: %d, TIMES : %d ms\n", getpid(), n+1, (end_time - start_time)*10);
							first = 0;
						}
						print_counter = PRINT_CYCLE;
					}
				}
			}
			printf(1,"PID: %d terminated\n", getpid());
			exit();
			
		}
	}

	for(; n > 0; n--){
		int p;
		if((p = wait()) < 0){
			printf(1, "wait stopped early\n");
			exit();
		}
	}	
	printf(1,"end of sdebug command\n");
}

int main(){
	sdebug_func();
	exit();
}
