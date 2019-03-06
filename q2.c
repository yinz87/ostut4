#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

void *bellcurve(double grade){
	char buffer[10];
	grade = grade *1.5;
	sprintf(buffer,"%.2f",grade);
	printf ("curved grade is %s \n",buffer);
}

int main(void)
{
	
	pthread_t thread[5];

	char grade[10];
	double grade_list[5];
	char buffer[10];

	for (int i = 0; i <5; i++){
	printf("please enter students's grade out of 100 in digits \n");
	fgets(grade,20,stdin);
	double x = atof(grade);
	grade_list[i] = x;}

	for (int j =0; j <5; j++){
		pthread_create(&thread[j], NULL,(void *)bellcurve(grade_list[j]),NULL);
	}

	exit(0);
	
}
