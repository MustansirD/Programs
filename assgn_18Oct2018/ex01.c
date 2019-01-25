#include<stdio.h>
#include"lib_myex01.h"
#include<stdlib.h>
void get_details(int num,char* name)
{
 printf("roll number & name is:%d\t%s\n",num,name);
 free(name);
}

int main()
{
	struct student s={.fptr = get_details};	
	fill_info(&s);
	
	return 0;
	
}
