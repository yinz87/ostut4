#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define NUMTHREADS 10

pthread_t thread[NUMTHREADS];
pthread_mutex_t mute;
double total_grade;


void *class_total(void * grade){
	pthread_mutex_lock(&mute);
	double gr = *(double *) grade;
	total_grade += gr;
	pthread_mutex_unlock(&mute);
}

int main(void)
{
	char grade[10];
	double grade_list[10];
	char buffer[10];

	for (int i = 0; i <NUMTHREADS; i++){
	printf("please enter students's grade out of 100 in digits \n");
	fgets(grade,20,stdin);
	double x = atof(grade);
	grade_list[i] = x;}

	if (pthread_mutex_init(&mute, NULL) !=0){
		printf("mutex init failed \n");
		return 1;	
	};
	
	for (int j =0; j <5; j++){
		pthread_create(&thread[j], NULL,class_total,&grade_list[j]);
	}

	for (int i=0; i< NUMTHREADS; i++){
		pthread_join(thread[i],NULL);
	}
	printf ("class total is %0.2lf \n", total_grade);
	pthread_mutex_destroy(&mute);

	pthread_exit(NULL);	
}
