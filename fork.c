#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 


int main() {

    pid_t pid;
    int refif = getpid ( ),i,n;
    printf("enter limit: ");
    scanf("%d",&n);
    pid = fork ( ); 
    
    for(i=0;i<n/2 +1;i++){

    if (pid > 0){
        printf ("%d ", i*2);
        printf ("parent pid=%d\n", getpid ( )); 
        sleep(1);
    }
    else if (!pid){
        printf ("%d ", i*2+1);
        printf ("child pid=%d\n", getpid ( )); 
        sleep(1);
    }

    }
    return 0;
} 
