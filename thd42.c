#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>

pthread_t tid[3];
char *ret[3];

// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
	unsigned long i = 0;
	char *msg = malloc(16);
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        printf("\n First Thread %lu\n", pthread_self());
		strcpy(msg, "First Done!");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[1]))
    {
        printf("\n Second Thread %lu\n", pthread_self());
		strcpy(msg, "Second Done!");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
	else
	{
		printf("\n Third Thread %lu\n", pthread_self());
		strcpy(msg, "Third Done!");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
	}

    for(i=0; i<(0xFFFFFFFF);i++);
} 
  
int main() 
{ 
    int i; 
    pthread_t sid; 
  
    // Let us create three threads 
    for (i = 0; i < 3; i++) {
        if (pthread_create(&(tid[i]), NULL, test_thread, (void *)&tid)){
			perror ("\npthread_create() error");
			exit(1);
		}
        sid = pthread_self();
		printf("\n This is main thread (%lu): Created %dth thread (%lu)... \n", sid, i+1, tid[i]);
	}
    
	pthread_join(tid[0], (void**)&(ret[0]));
    pthread_join(tid[1], (void**)&(ret[1]));
	pthread_join(tid[2], (void**)&(ret[2]));
	
	printf ("\nThread %lu said %s", tid[0], ret[0]);
    printf ("\nThread %lu said %s", tid[1], ret[1]);
	printf ("\nThread %lu said %s", tid[2], ret[2]);
	
	printf ("\n Main Thread %lu exitting.. " , pthread_self());
    return 0; 
} 