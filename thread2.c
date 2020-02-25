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
    int p1[2],p2[2];
    printf("enter firsdt set of numbers: ");
    scanf("%d %d",&p1[0],&p1[1]);
    printf("enter second set of numbers: ");
    scanf("%d %d",&p2[0],&p2[1]);


    pthread_t tid1,tid2;
    pthread_create(&tid2,NULL,add,p1);
    pthread_create(&tid1,NULL,add,p2);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}
