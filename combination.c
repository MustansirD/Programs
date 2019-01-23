#include<stdio.h>
#define size 6
#define sum 5

int main(){
	int a[size] = {0,1,4,3,2,5};
	int i,j;
	int count = 0;
	
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(a[i]+a[j]==sum)
				count=count+1;
		}
	}
	
	printf("Number of combination posssible are %d\n",count);
	return 0;
}
