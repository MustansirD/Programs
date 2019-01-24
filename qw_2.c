#include<stdio.h>

int const a=10;
int *ptr = &a;

int main()
{

	*ptr = 20;
	printf("%d\n", *ptr);
	return 0;
}
