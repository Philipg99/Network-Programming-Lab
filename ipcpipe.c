#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <signal.h>
#include <assert.h>
#include <pthread.h>

int msg1 = 1; 

int p1[2],p2[2];
int inbuf; 
int nbytes; 


void *pro1(void *arg)
{	
	int c=1;
        write(p1[1], const void *msg1, sizeof(msg1)); 
 
	sleep(1);
	while (c-- > 0){
	    read(p2[0], inbuf, sizeof(msg1));
            printf("%d\n", inbuf); 
 }
  
}
void *pro2(void *arg)
{
    int c=1,i;
    while (c-- > 0){
	    read(p1[0], inbuf, sizeof(msg1));
            printf("%d\n", inbuf); 
 }

   write(p2[1],const void *msg1, sizeof(msg1)); 

}

int main() 
{
    pthread_t tid1,tid2;
  
    if (pipe(p1) < 0) 
        exit(1); 
    if (pipe(p2) < 0) 
        exit(1);
  
    pthread_create(&tid2,NULL,pro1,NULL);
    pthread_create(&tid1,NULL,pro2,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}
