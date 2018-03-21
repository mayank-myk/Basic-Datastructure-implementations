//mayank agrawal
//150101033
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int n;

struct node {
        int id;
        char colour;
        struct node* next ;
};

struct node* createnode(){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        return temp;
}
//function to form the adjacency lust
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
                cout<< temp->id << " ";
                temp=temp->next;
        }
        cout<< endl;
    }
}

void dfs(struct node* g,int i,stack<int>* visited){
	int j;
    (g+i)->colour='g';
    struct node* temp = g+i;
    while((temp->next)!=NULL){
    	temp = temp->next;
    	j=temp->id;
        if((g+j)->colour=='w'){
            dfs(g,j,visited);
            visited->push(j);
        }
    }
}

void dfs1(struct node* g, int i,int count, int* component){
	int j;
    (g+i)->colour='g';
    component[i]=count;
    cout << i << " " ;
    struct node* temp = g+i;
    while((temp->next)!=NULL){
    	temp = temp->next;
    	j=temp->id;
        if( (g+j)->colour=='w'){
            dfs1(g,j, count, component);
        }
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

struct node* components(struct node* g,int* component, int count){
	int j;
    count--;
    struct node* b=(struct node *)malloc(sizeof(struct node)*(count+1));
    for(int i=1;i<=count;i++){
        (b+i)->id=i;
        (b+i)->next=NULL;
        (b+i)->colour='w';
    }
    int arr[count+1][count+1]={0};
    for(int i=1;i<=n;i++){
    	struct node* temp=g+i;
        while((temp->next)!=NULL){
        	temp=temp->next;
        	j=temp->id;
            if(component[i]!=component[j] && arr[component[i]][component[j]]==0){
                connect(b,component[i], component[j]);
                arr[component[i]][component[j]]=1;
            }
        }
    }
    return b;
}

void scc(struct node* g){
    
    //first DFS
    stack<int> visited;
    for(int i=1;i<=n;i++){
        if( (g+i)->colour=='w'){
            dfs(g,i,&visited);
            visited.push(i);
        }
    }
    //calculating the transpose
    struct node *b = transpose(g);

    //second DFS
    int count=1, component[n],k;
    while(!visited.empty()){
        k=visited.top();
        if( (b+k)->colour=='w'){
            cout << "Strongly Connected component number " << count << ": " ;
            dfs1(b,k,count,component);
        }
        visited.pop();
        count++;
        cout<<endl;
    }
    //finding out the component graph
    struct node* c = components(g,component, count);
    //"Example if scc number 1 and scc number 2 are connected then it shows 1-> 2
    print(c, count);
}

int main(){

        int e,i,n1,n2;
        cout<< "Enter the no. of nodes: " ;
        cin >> n ;
        cout<< "Enter the no. of edges: " ;
        cin >> e ;
        struct node* g=(struct node *)malloc(sizeof(struct node)*(n+1));
        for(i=1;i<=n;i++){
            (g+i)->id=i;
            (g+i)->next=NULL;
            (g+i)->colour='w';
        }
        for(i=0;i<e;i++){
            cout<< "Enter the pair of connected id: "<< endl;
            cin >> n1>>n2 ;
            connect(g,n1,n2);
        }
        scc(g);
        return 0;
}