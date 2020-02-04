#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 


int main() {

    pid_t pid;
    int refif = getpid ( ),i,n=10; 
    pid = fork ( ); 

    for(i=0;i<n;i++){

    if (pid > 0){
        printf ("%d ", i*2);
        printf ("My pid=%d\n", getpid ( )); 
        sleep(1);
    }
    else if (!pid){
        printf ("%d ", i*2+1);
        printf ("My pid=%d\n", getpid ( )); 
        sleep(1);
    }

    }
    return 0;
} 