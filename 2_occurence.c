#include<stdio.h>
#include<stdlib.h>

struct node{
	char character;
	int freq;
	struct node *next;

};

struct node* head = NULL;

void insertData(char *str){
	struct node *current = (struct node *)malloc(sizeof(struct node));
	current->character = *str;
	current->freq = current->freq+1;
	current->next = NULL;
	
	if(head == NULL){
		head = current;
	//	current->next = NULL;
		return;
	}
	struct node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = current;
	return;
}

void displayData(){
	if(head == NULL){
                printf("There are no nodes except the head pointer!!!!\n");

        }
        else{
                struct node* temp = head;
                while(temp!=NULL){
                        printf("%c %d\n",temp->character,temp->freq);
                        temp = temp->next;
                }
               
        }

}



char flag[128];

void count(char *str){
	char arr[128];
	int i;
	for(i=0;i<128;i++){
		arr[i] = 0;
		flag[i] = 0;
	}
//	exit(0);
	while(*str!='\0')
{
		struct node *temp=head;
		if(flag[*str]==0){
		insertData(str);
	//	arr[*str] = arr[*str]+1;
		flag[*str] = 1;
		}else{
	//	struct node *temp = head;
		while(temp->character!=*str)
		temp = temp->next;
		temp->freq++;
		}
			
		str++;
	}
	
	
}
int main(){
	char *str;
	str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	count(str);
	displayData();
	return 0;

	
}


