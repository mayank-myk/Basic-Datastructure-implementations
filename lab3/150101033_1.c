//MAYANK AGRAWAL
//ROLL NO. 150101033

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
    int key;
    int cost;
    struct node *left;
    struct node *right;
    string title;
    string author; 
    int publication_year;
    int copies_sold;
}node;

struct node *newNode(){
    node *temp =  new struct node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
void increase(node *root){

    if (root == NULL)
        return ;
    root->cost=(root->cost)*(1.1);
    inorder(root->left);
    printf("%d \n", root->key);
    inorder(root->right);   
}

node* insert(node* root){
    if (node == NULL) 
        return create_node();
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}

node* cost_search(struct node* root, int key){
    if (root == NULL || root->key == key)
       return root->copies_sold;
    
    else if (root->key < key)
       return cost_search(root->right, key);
 
    else if (root->key > key)
        return cost_search(root->left, key);

    else return -1;
}

void print(node *root){

    if (root == NULL)
        return ;
    inorder(root->left);
    cout<< "ISBN: "<< root->key <<",  "<<"author: "<< root->author <<",  "<<"cost: " <<root->cost<<endl;
    cout<<"year of publication: "<<root->publication_year<<"   "<<"copies sold:"<<root->copies_sold<<",  "<<"title"<<root->title<<endl;
    cout<<endl;
    inorder(root->right);   
}

int main(){

    int arr[100]= {0} ;
    struct node *root;
    for(int i=0;i<50;i++){
        root=randomtree();
        int x = ( maxHeight(root) - minHeight(root));
        arr[x]++ ;   
    }
    for(int i=0;i<50;i++){ 
        if( arr[i] != 0){
            printf("number of trees with difference in depth of %d is %d\n",i,arr[i]);
        }  
    }
 
    return 0;
}