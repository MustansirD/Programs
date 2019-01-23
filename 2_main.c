#include<stdlib.h>
#include<stdio.h>

int main(){
	int *p = malloc(8);
	printf("address of p %p\n",p);
	*p=100;
	printf("value before free : %d\n",*p);
//	free(p);
	int *q = malloc(8);
	printf("address of q %p\n",q);

//	printf("value after free : %d\n",*p);
//	*p = 110;
//	printf("value %d\n",*p);
	return 0;	
}
