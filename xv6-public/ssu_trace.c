#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
	
	int pid, mask_num = 0;
	char *trace_argv[argc-1];
	
	mask_num = atoi(argv[1]);
	// command 부분 인자 저장 배열
	for(int i=2;i<argc;i++){
		trace_argv[i-2] = argv[i];
	}
	argv[argc-2] = 0;

	pid = fork();
	if(pid < 0){
		printf(1, "ssu_trace : fork failed\n");
		exit();
	}

	if(pid == 0){
			trace(mask_num);
		exec(argv[2], trace_argv);
		printf(1, "ssu_trace exec %s failed\n", argv[2]);
		exit();
	}
	wait();
	exit();

}
