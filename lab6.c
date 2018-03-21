#include <stdio.h>
#include <stdlib.h>

int n,count=0,array[10]={0};

struct node {
        int id;
        char colour;
        struct node* next ;
};

struct node* createnode(){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        return temp;
}

void connect(struct node* g,int i,int j){

        struct node* temp= g+i ;
        while( (temp->next)!=NULL){
                temp=temp->next;
        }
        temp->next=createnode();
        temp->next->id=j;
        temp->next->colour='w';
        temp->next->next=NULL;
}

void print(struct node *g,int k){
    for(int i=1;i<=k;i++){
        struct node* temp= g+i ;
        while( temp!=NULL){
                printf("%d ",temp->id);
                temp=temp->next;
        }
        printf("\n");
    }
}

struct node * transpose( struct node * g){
        int x;
        struct node * a = ( struct node *)malloc(sizeof( struct node )*( n+1 ) );
        for(int i=1;i<=n;i++){
                (a+i)->id=i;
                (a+i)->next=NULL;
                (a+i)->colour='w';
        }
        for (int i=1;i<=n;i++){
                struct node *temp=g+i;
                while(temp->next!=NULL){
                        temp=temp->next;
                        x=temp->id;
                        connect(a,x,i);
                }
        }
        return a;
}

void DFS_visit(struct node* g,int u){

        int i;
        struct node* temp=g+u;
        temp->colour='g';
        while( (temp->next)!= NULL ){
                temp=temp->next;
                i= temp->id ;
                if((g+i)->colour=='w'){
                        printf("%d ",(g+i)->id );
                        DFS_visit(g,i);
                }
        }
        count ++ ;
        array[count]=(g+u)->id;
}

void DFS(struct node* g, int a[]){

        int i;
        for(i=1;i<=n;i++){
                if((g+a[i])->colour=='w'){
                        printf("%d ",(g+a[i])->id);
                        DFS_visit(g,a[i]);
                }
                printf("\n");
        }
}

struct nodeHead* createCompGraph(struct nodeHead* graph, int V, int* component, int count){
    bool components=false;
    struct nodeHead* comp = createGraph(count);
    struct node* temp;
    for(int i=0;i<V;i++){
        temp = graph[i].head;
        while(temp!=NULL){
            if(component[i]!=component[temp->vert]){
                addEdge(comp, component[i]-1, component[temp->vert]-1);
                components=true;
            }
            temp=temp->next;
        }
    }
    if(components==false){
        cout << endl << "Single Component. All are connected";
    }
    return comp;
}

void scc(struct node *g){

        int arr[n+1],arr1[n+1],i;
        for(i=1;i<=n;i++){
                arr[i]=i;
        }
        DFS(g,arr);
        struct node *b = transpose(g);
        count=0;
        for(i=1;i<=n;i++){
                arr1[i]=array[n-i+1];
                array[n-i+1]=0;
        }
        DFS(b,arr1);
}

int main(){

        int e,i,n1,n2;
        printf("Enter the no. of nodes:");
        scanf("%d",&n);
        printf("Enter the no. of edges:");
        scanf("%d",&e);
        struct node* g=(struct node *)malloc(sizeof(struct node)*(n+1));
        for(i=1;i<=n;i++){
                (g+i)->id=i;
                (g+i)->next=NULL;
                (g+i)->colour='w';
        }
        for(i=0;i<e;i++){
                printf("Enter the pair of connected id's:\n");
                scanf("%d %d",&n1,&n2);
                connect(g,n1,n2);
        }
        print(g);
         scc(g);
        return 0;
}