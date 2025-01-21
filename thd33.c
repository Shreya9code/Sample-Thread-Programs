#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
    // Store the value argument passed to this thread 
    pthread_t *thd_id = (pthread_t*)arg; 
    pthread_t sid;
    sid = pthread_self();
    printf("Hello from new thread %lu got %lu!\n",sid,*thd_id); 
	//pthread_exit(NULL); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid, sid; 
  
    // Let us create three threads 
    for (i = 0; i < 3; i++) {
        if (pthread_create(&tid, NULL, test_thread, (void *)&tid)){
			perror ("\npthread_create() error");
			exit(1);
		}
        sid = pthread_self();
		printf("\n This is thread (%lu): Created new thread (%lu)... \n", sid, tid);
	}
    //pthread_exit(NULL); 
    return 0; 
} 