#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

struct student{
	char name[50];
	char student_id[50];
	double grade;} ;


void *bellcurve(struct student s){
	s.grade = s.grade *1.5;
	char buffer[10];
	sprintf(buffer,"%.2f",s.grade);
	printf ("curved grade is %s \n",buffer);


}

int main(void)
{	
	struct student std[5];
	pthread_t thread[5];

	for (int i = 0; i <5; i++){
		printf("please enter students's name \n");
		scanf("%s",std[i].name);
		printf("please enter students's ID \n");
		scanf("%s",std[i].student_id);
		printf("please enter students's grade out of 100 in digits \n");
		scanf("%lf",&std[i].grade);}

	for (int j = 0; j < 5; j++){
		pthread_create(&thread[j], NULL,(void *)bellcurve(std[j]),NULL);
}
	exit(0);
}
