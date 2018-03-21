#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *ptr;
};

struct node* head=NULL;

struct node* createnode (){
	printf("enter node value:");
	int i;
	scanf("%d",&i);
	struct node *temp;
	temp =(struct node*)malloc(sizeof(struct node));
	temp->data=i;
	temp->ptr=NULL;
	return temp;
}

void create_first_node(){	
	printf("for entering new node at start, ");
	head=createnode();
	
}

void insertatstart(struct node* ptr1){
	struct node* temp=createnode();
	if(ptr1!=NULL){
		temp->ptr=ptr1 ;
	}
	ptr1 = temp ;
	head=ptr1;
}

void insertatend(struct node* ptr1){
	struct node* temp=ptr1;
	while(temp!=NULL && temp->ptr!=NULL){
		temp=temp->ptr;
	}
	struct node* q=createnode();
	temp->ptr =q;	
}

void insertafter(struct node* ptr1){
	printf("enter node value after which you want to insert node:");
	int i;
	scanf("%d",&i);
	struct node* temp=ptr1;
	while(temp && temp->data != i){
		temp=temp->ptr;
	}
	if(temp!=NULL){
		struct node* q=createnode();
		q->ptr=temp->ptr;
		temp->ptr=q;	
	}
}

void deletestart(){
	head=head->ptr;
}

void deleteend(struct node* ptr1){
	struct node* temp=ptr1;
	while(((temp->ptr)->ptr)!=NULL){
		temp=temp->ptr;
	}
	struct node * q;
	q=temp->ptr;
	temp->ptr=NULL;
	free(q);	
}

void deleteafter(struct node* ptr1){
	printf("enter node value after which you want to delete node:");
	int i;
	scanf("%d",&i);
	struct node* temp=ptr1;
	while( (temp->data) != i){
		temp=temp->ptr;
	}
	struct node * q;
	q=temp->ptr;
	temp->ptr=q->ptr;
	free(q);		
}

void display(struct node* ptr1){
	struct node* temp=ptr1;
	while(temp!=NULL){
		printf("%d  ",temp->data);
		temp=temp->ptr;
	}
	printf("\n");
}

int main(){
	printf("for linked list question\n");
	create_first_node();
	display(head);
	printf("press 1->insert start\npress 2->insert between\npress 3->insert end\npress 4->delete start\npress 5->delete after\npress 6->delete end\npress 7-> exit\n");
	int y;

while(1){
	printf("give a choice bro:  ");
	scanf("%d",&y);
	switch(y){

		case 1: {
			insertatstart(head);
			break;
		}
		case 2: {
			insertafter(head);
			break;
		}
		case 3: {
			insertatend(head);
			break;
		}
		case 4:{
			deletestart();
			break;
		}
		case 5:{
			deleteafter(head);
			break;
		}
		case 6:{
			deleteend(head);
			break;
		}
		case 7:{
			return 0;
		}
		default:{
			break;
		}

	}
	display(head);
}

//stack question starts
	head=NULL;
	printf("for stack question\n");
	create_first_node();
	display(head);
	printf("press for push->1 , pop->2 , end->3\n");
	int z;
	while(1){
		scanf("%d",&z);
		if(z==3){
			break;
		}
		else{
			if(z==1){
				insertatend(head);
			}
			else{
				deleteend(head);
			}

		}
		display(head);
	};

	
//queue question starts
	printf("for queue question\n");
	head=NULL;
	create_first_node();
	display(head);
	printf("press for insert->1 , delete->2 , end->3\n");
	int t;
	while(1){
		scanf("%d",&t);
		if(t==3){
			break;
		}
		else{
			if(t==1){
				insertatend(head);
			}
			else{
				deletestart(head);
			}

		}
		display(head);
	}


	return 0;
}
