#include<stdio.h>

int main(){
	int arr[4] ={5,4,3,2};
	int i,j,temp;
	
	for(i=0;i<4;i++){
		for(j=i+1;j>0;j--){
			if(arr[j]<arr[j-1]){
				temp = arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;	
			}
		}	
		
		
	}

	printf("Sorted array using is\n");
	
	for(i=0;i<4;i++){
		printf("%d\n",arr[i]);
	}

return 0;
}
