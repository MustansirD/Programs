#include<stdio.h>

void count(char *str){
	char arr[128];
	int i;
	for(i=0;i<128;i++){
		arr[i] = 0;
	}
	
	while(*str!='\0'){
	
		arr[*str] = arr[*str]+1;
		str++;
	}
	
	for(i=0;i<128;i++){
		if(arr[i]!=0){
			printf("occurence of character %c is %d times \n",i,arr[i]);
		}
	}
}
int main(){
	char *str;
	str = "Mustansir";
	count(str);
	return 0;

	
}


