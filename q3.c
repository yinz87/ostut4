#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

struct student{
	char name[50];
	char student_id[50];
	double grade;};


void *bellcurve(struct){
	char buffer[10];
	grade = grade *1.5;
	sprintf(buffer,"%.2f",grade);
	printf ("curved grade is %s \n",buffer);
}

int main(void)
{	
	struct student s;
	pthread_t thread[5];

	for (int i = 0; i <5; i++){
	printf("please enter students's name \n");
	fgets(&s.name,50,stdin);
	printf("please enter students's ID \n");
	fgets(&s.student_id,50,stdin);
	printf("please enter students's grade out of 100 \n");
	fgets(&s.grade,50,stdin);}

}
