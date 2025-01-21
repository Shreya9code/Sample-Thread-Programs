#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

pthread_t tid[3];
// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
	unsigned long i = 0;
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        printf("\n First Thread %lu\n", pthread_self());
    }
    else if (pthread_equal(id,tid[1]))
    {
        printf("\n Second Thread %lu\n", pthread_self());
    }
	else
	{
		printf("\n Third Thread %lu\n", pthread_self());
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
    
    sleep(5);	
    return 0; 
} 