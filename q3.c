#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define NumThread 5

struct student{
	char name[50];
	char student_id[50];
	double grade;};


void *bellcurve(void *student){
	struct student *data = (struct student *) student;
	data -> grade = data -> grade *1.5;
	char buffer[10];
	sprintf(buffer,"%.2f",data ->grade);
	printf ("curved grade is %s \n",buffer);
	pthread_exit(NULL);
}

int main(void)
{	
	struct student std[NumThread];
	pthread_t thread[NumThread];

	for (int i = 0; i <NumThread; i++){
		printf("please enter students's name \n");
		scanf("%s",std[i].name);
		printf("please enter students's ID \n");
		scanf("%s",std[i].student_id);
		printf("please enter students's grade out of 100 in digits \n");
		scanf("%lf",&std[i].grade);}

	for (int j = 0; j < NumThread; j++){
		pthread_create(&thread[j], NULL,bellcurve,&std[j]);
}
	for (int i=0;i<NumThread;i++){
		pthread_join(thread[i],NULL);
}
}
