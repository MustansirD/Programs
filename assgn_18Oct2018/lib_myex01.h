#ifndef LIB_EX01_H
#define LIB_EX01_H 
struct student
{
	
	int roll_num;
	char* name;	
	void (*fptr)(int num,char* name);
};

void fill_info(struct student*);

#endif

