#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <signal.h>
#include <assert.h>
#include <pthread.h>



void *add(void *arg)
{
    int *intarg;
    intarg = arg;

    printf("%d + %d = %d\n",intarg[0],intarg[1],intarg[0]+intarg[1]);

    return NULL;
}

int main() 
{
    int global[2];

    printf("enter the numbers: ");
    scanf("%d %d",&global[0],&global[1]);

    pthread_t tid_sum;
    pthread_create(&tid_sum,NULL,add,global);
    pthread_join(tid_sum,NULL);

    return 0;
}
