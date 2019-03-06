#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void *hello_world(){
	srand(time(0));
	sleep(rand()%5);
	printf("hello world \n");
}

void *goodbye(){
	srand(time(0));
	sleep(rand()%5);
	printf("goood bye \n");
}

int main(void)
{
	pthread_t thread_id1;
	pthread_t thread_id2;
	pthread_create(&thread_id1, NULL, (void *)hello_world, NULL);
	pthread_create(&thread_id2, NULL, (void *)goodbye, NULL);
	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);

	return 0;
}
