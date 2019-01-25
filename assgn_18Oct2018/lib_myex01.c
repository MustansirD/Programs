#include"lib_myex01.h"
#include<stdio.h>
#include<stdlib.h>

void fill_info(struct student *s1)
{
	printf("Enter roll number:\n");
	scanf("%d",&s1->roll_num);

	s1->name =(char*)malloc(50);
	printf("Address for char:%ld\n",s1->name);
	printf("Enter name:\n");
	scanf("%s",s1->name);
	s1->fptr(s1->roll_num,s1->name);
}


