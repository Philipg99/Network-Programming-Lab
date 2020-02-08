#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <signal.h>

void sigint_handler (int signo){

	printf ("Caught SIGINT!\n");
	exit (EXIT_SUCCESS);
}
void sigint_handler2 (int signo){

	printf ("Caught SIGCHLD!\n");
	
}

int main() {

    pid_t pid;
    int refif = getpid ( ),i,n;
    pid = fork ( ); 



    if (pid > 0){
	printf("parent running\n");
        while(1==1){
	signal (SIGCHLD, sigint_handler2);
   	 signal (SIGINT, sigint_handler);
    	}
    }
    if (!pid){
	
        printf("child running\n");
        sleep(1);
	
    }
 
    
    return 0;
}
