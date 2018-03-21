// MAYANK AGRAWAL
//150101033
#include<stdio.h>
#include<stdlib.h>

int n; // No. of vertices

struct node{
    struct node* next;
    int id;
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

void dfs(struct node* g,int j, int k,int **c){

    c[j][k] = 1;
    if(k==0){
        k=j;
    }
    int i;
    // recursively search for all the vertices having a path from j
    struct node* temp=g+k;
    while((temp->next) != NULL){
        temp=temp->next;
        i= temp->id ; 
        if(c[j][i]==0){ 
            dfs(g,j,i,c) ;
        }
    }
}
 
void dfs_visit(struct node* g){
  
    int i,j;
    // 2-D array for storing the check response between pair of nodes
    int ** check ;
    check = (int **)malloc(sizeof(int *)*(n+1) );
    for (i=1; i<=n; i++){
        check[i] = (int *)malloc(sizeof(int)*(n+1) );
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            check[i][j]=0;// initialising to 0
        }       
    }

    for (int i = 1; i <= n; i++){
        dfs(g,i, 0,check); 
    }
    // 1 if their exists a path
    // 0 if their dosen't exist a path
    printf("matrix is \n");
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            printf("%d ",check[i][j] );
        }
        printf("\n");
    }
}

int main(){
    int e,i,n1,n2;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    printf("Enter the no. of edges: ");
    scanf("%d",&e);

    struct node* g=(struct node*)malloc((n+1)*sizeof(struct node));

    for(i=1;i<=n;i++){
        (g+i)->id=i ;
        (g+i)->next=NULL;
    }
    for(i=0;i<e;i++){
        printf("Enter the pair of connected id's: ");
        scanf("%d %d",&n1,&n2);
        connect(g,n1,n2);
    }
    dfs_visit(g);
    
    return 0;
}