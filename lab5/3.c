// MAYANK AGRAWAL
// 150101033
#include<stdio.h>
#include<stdlib.h>

int t=0;

struct node{
	struct node* next;
	int id;
	char colour;
};

struct node* createnode(){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	return temp;
}
// function to form the adjacency list
void connect(struct node* g,int i,int j){

	struct node* temp= g+i ;
	while( (temp->next)!=NULL){
		temp=temp->next;
	}
	temp->next=createnode();
	temp->next->id=j;
	temp->next->next=NULL;		
}
/* 
white indicates a tree edge
gray indicates a back edge
black indicates a forward or cross edge */

// recursively visit every vertex of adjaceny list
void DFS_visit(struct node* g,int u,int n,int d[],int f[]){

	int i;
	struct node* temp=g+u;
	temp->colour='g';
	t ++;
	d[u]=t;
	while((temp->next) != NULL){
		temp=temp->next;//go to the first element of array
		i= temp->id ;	
		if((g+i)->colour=='w'){
			printf("edge (%d,%d) is tree edge\n",(g+u)->id,(g+i)->id );
			DFS_visit(g,i,n,d,f);
			continue;
		}
		if((g+i)->colour=='g'){
			printf("edge (%d,%d) is back edge\n",(g+u)->id,(g+i)->id );
		}
		if((g+i)->colour=='b'){
			if(d[u] < d[i]){
				printf("edge (%d,%d) is forward edge\n",(g+u)->id,(g+i)->id );
			}
			else if(d[u] > d[i]){
				printf("edge (%d,%d) is cross edge\n",(g+u)->id,(g+i)->id );
			}
		}
	}
	(g+u)->colour='b';
	t ++;
}
// DFS visit to every vertex
void DFS(struct node* g, int n){

	int d[n+1],f[n+1];
	int i;
	for(i=1;i<=n;i++){
		if((g+i)->colour=='w'){
			DFS_visit(g,i,n,d,f);
		}
	}	
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
	}
	DFS(g,n);
	return 0;
}

