#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* next;
	int id;
	char colour;
};

struct node* createnode(){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	return temp;
}

void connect(struct node* g,int i,int j){

	struct node* temp= g+i ;
	while( (temp->next)!=NULL){
		temp=temp->next;
	}
	temp->next=createnode();
	temp->next->id=j;
	temp->next->next=NULL;		
}

void DFS_visit(struct node* g,int j){
	
	int i;
	struct node* temp=g+j;
	temp->colour='g';
	while((temp->next) != NULL){
		temp=temp->next;//go to the first element of array
		i= temp->id ;	
		if((g+i)->colour=='w'){
			printf("%d ",(g+i)->id);
			DFS_visit(g,i);
		}
	}
}

void DFS(struct node* g, int n){
	int i,count=0;
	for(i=1;i<=n;i++){
		if((g+i)->colour=='w'){
			count++;
			printf("connected Component %d: %d ",count,(g+i)->id);
			DFS_visit(g,i);
			printf("\n");
		}
	}	
	printf("\nTotal no. of connected components are: %d\n",count);	
}

int main(){
	int n,e,i,n1,n2;
	printf("Enter the no. of nodes: ");
	scanf("%d",&n);
	printf("Enter the no. of edges: ");
	scanf("%d",&e);

	struct node* g=(struct node*)malloc((n+1)*sizeof(struct node));

	for(i=1;i<=n;i++){
		(g+i)->id=i ;
		(g+i)->next=NULL;
		(g+i)->colour='w';
	}
	for(i=0;i<e;i++){
		printf("Enter the pair of connected id's: ");
		scanf("%d %d",&n1,&n2);
		connect(g,n1,n2);
		connect(g,n2,n1);
	}
	DFS(g,n);
	return 0;
}

