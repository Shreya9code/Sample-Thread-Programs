#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
// Let us create a global variable to change it in threads 
int g = 0; 
  
// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
    // Store the value argument passed to this thread 
    pthread_t thd_id = (pthread_t)arg; 
  
    // Let us create a static variable to observe its changes 
    static int s = 0; 
    int t = 0;
    // Change static and global variables 
    ++s; ++g; ++t; 
  
    // Print the argument, static and global variables 
    printf("Thread ID: %lu, Static: %d, Global: %d, Local: %d\n", thd_id, ++s, ++g, ++t); 
	pthread_exit(NULL); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid; 
  
    // Let us create three threads 
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, test_thread, (void *)tid); 
  
    pthread_exit(NULL); 
    return 0; 
} 