// mayank agrawal
// 150101033

//their is small error
//please try for less inputs
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
int deb;
typedef struct node{
    int n;
    int degree;
    node* parent;
    node* child;
    node* left;
    node* right;
}node;

typedef struct heap{
    int key;
    struct node *min; 
}heap;

struct heap* create_heap(){
    struct heap *H=new struct heap;
    H->min=NULL;
    H->key=0;
    return H;
}

node* create_node(){ 
    int value;  
    node* x = new node;
    return x;
}

//method is exactly as given in cormen

struct heap* Insert(heap* H){
    int value;
    node *x=create_node();
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->left = x;
    x->right = x;
    cout << "give the value:  " ;
    cin >> value ;
    x->n = value;
    node *min_ptr=H->min;
    if(min_ptr==NULL){
        H->min= x;
    }
    else{
        (min_ptr->left)->right = x;
        x->right = min_ptr;
        x->left = min_ptr->left;
        min_ptr->left = x;
        if (x->n < min_ptr->n)
            H->min = x;
    }
    H->key = H->key + 1;
    return H;
}

node* Union(heap* H1,heap* H2){

    node* H =create_heap();
    H = H1;
    (H->left)->right = H2;
    node *temp=H->left;
    H->left = H2->left;
    (H2->left)->right = H;
    H2->left = temp;
    if(H1==NIL || (H2!=NIL && H2.min<H1.min)){
        H=H2;
    }
    return H;
}

void Fibonnaci_link(heap* H1, node* y, node* z){

    node *min_ptr=H1->min;
    
    (y->left)->right = y->right;
    (y->right)->left = y->left;
    
    if (z->right == z)
        H1->min = z;
    
    y->left = y;
    y->right = y;
    y->parent = z;
    
    if (z->child == NULL)
        z->child = y;
    
    y->right = z->child;
    y->left = (z->child)->left;
    ((z->child)->left)->right = y;
    (z->child)->left = y;
    
    z->degree++;
}

heap *Consolidate(heap* H1){
    
    int d,D;
    node* x = H1->min;
    node* y;
    node *np;
    node *min_ptr=H1->min;
    D = H1->key;
    node* A[D+1];
    for (int i = 0; i <= D; i++)
        A[i] = NULL;

    int count;
    do{
        x=x->right;
        count++;

    }
    while(x!=min_ptr);
   
    do{
        d = x->degree;
        while (A[d] != NULL){
            y = A[d];
            if (x->n > y->n){
                np = x;
                x = y;
                y = np;
            }
            if (y == H1->min)
                H1->min = x;
            Fibonnaci_link(H1, y, x);
            if (x->right == x)
                H1->min = x;
            A[d] = NULL;
            d = d + 1;
        }
        A[d] = x;
        x = x->right;
    }
    while (x != H1->min);

    min_ptr = NULL;
    heap *H2;
    for (int j = 0; j <= D; j++){
        if (A[j] != NULL){
            A[j]->left=A[j];
            A[j]->right=A[j];
            if(min_ptr==NULL){
                H2=create_heap();
                H2->min = A[j];
                min_ptr=A[j];
            }
            else{
        
            (min_ptr->left)->right = A[j];
                A[j]->right = H2->min;
                A[j]->left = H2->min->left;
                H2->min->left = A[j];
                if (A[j]->n < H2->min->n)
                    H2->min = A[j];
            }   
        }
   }
   H2->key = H1->key;
   return H2; 
}

heap* Extract_Min(heap* H1){
    int j,k,m;
    node* z = H1->min;
    node* ptr;
    node *x=NULL;
    node* np;
    heap *H2;

    if (z!= NULL){
        if (z->child != NULL){
            x = z->child;
        }
        if (x != NULL){
            ptr = x;
            do{
                x->left->right = NULL;
                np = x->right;
                (z->left)->right = x;
                x->right = z;
                x->left = z->left;
                z->left = x;
                x->parent = NULL;
                x = np;
            }
            while (np != NULL);
        }
        (z->left)->right = z->right;
        (z->right)->left = z->left;

        if (z == z->right && z->child == NULL)
            H1->min = NULL;
        else{
            H1->min = z->right;
            H1=Consolidate(H1);
        }
        H1->key = H1->key - 1;
    }
    cout << "the value is:  " << z->n << endl;
    return H1;
}

void printSpace(int n){
    while(n--)
    cout<<"  ";
}

void printNode(node* temp, int t,int sp){
            //cout<<"\n print node called by : "<<t<<endl;  
    node* minhere = temp;
            
    if(temp==NULL)
        return;
    printSpace(sp);
    cout<<temp->n<<endl;

    if(temp->child!=NULL)
        printNode(temp->child, temp->n, sp+4);

    temp = temp->left;
        
    while(temp!=minhere){
        printSpace(sp);
        cout<<temp->n<<endl;
        if(temp->child!=NULL)
            printNode(temp->child, temp->n,sp+4);
        temp = temp->left;
    }
    return;
}

void showHeap(heap *H1){
    cout<<endl;
    node* temp = H1->min;
    cout<<temp->n<<endl;
        
    if(temp->child!=NULL)
        printNode(temp->child, temp->n,4);
    temp = temp->left;
            
    while(temp!=H1->min){
        cout<<temp->n<<endl;
        if(temp->child!=NULL)
            printNode(temp->child, temp->n,4);
        temp = temp->left;
    }
    cout<<endl;
    }

    
int main(){

heap *H1=create_heap();
int a;
while(1){
    cout<< "input 1--> for insert , 2--> for extract_min,3--> for show_heap any other to exit" <<endl;
    cin >> a;
    switch(a){
        case 1:{
            H1=Insert(H1);
            break;
        }
        case 2:{
            H1=Extract_Min(H1);
            break;
        }
        case 3:
            showHeap(H1);
            break;
        default:
            exit(0); 
    }
}
return 0;
}
    