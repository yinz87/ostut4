#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define NUMTHREADS 5
pthread_t thread[NUMTHREADS];

void *bellcurve(void * grade){
	char buffer[10];
	double gr =  *((double*)grade);
	gr = gr*1.5;
	sprintf(buffer,"%.2f",gr);
	printf ("curved grade is %s \n",buffer);
	pthread_exit(NULL);
}

int main(void)
{

	char grade[10];
	double grade_list[5];
	char buffer[10];

	for (int i = 0; i <NUMTHREADS; i++){
	printf("please enter students's grade out of 100 in digits  \n");
	fgets(grade,20,stdin);
	double x = atof(grade);
	grade_list[i] = x;}

	for (int j =0; j <NUMTHREADS; j++){
		pthread_create(&thread[j], NULL,bellcurve,&grade_list[j]);
	}
	for (int k=0; k< NUMTHREADS; k++){
		pthread_join(thread[k],NULL);
	}
	
}
