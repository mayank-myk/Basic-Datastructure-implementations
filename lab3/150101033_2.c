//MAYANK AGRAWAL
//ROLL NO. 150101033

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int count = 0,count1=0;

//defining the struct node which consist of key and pointer to left and right child
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

//Creates new node ,puts the data into it and initializes left and right to NULL.
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
/* Inserts the element in correct position i.e. if data < node->data insert it into right subtree
  and if it is less then insert it in left subtree. */ 
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}

//creating tree using rand() function
struct node *randomtree(){

    struct node *temp_root = NULL;
    srand(time(NULL)+count);
    count++;
    int t; 
    temp_root = insert(temp_root, 1); /* initializing the tree */
    for(int i=0;i<99;i++){
        t=rand()%1000;
        insert(temp_root, t); //using numbers from random function to insert
    }

    return temp_root;
}

//function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d, ", root->key);
        inorder(root->right);
    }
}

//function to count number of leafs recurssively
void count_leaves(struct node *root)
{	
	//count increses if the left and right child points to null and the parent itself is not a null node 
    if( (root!= NULL) && (root->left == NULL) && (root->right == NULL) )
    {
        count1++;
    }
    if( root!= NULL)
    {
        count_leaves(root->left);
        count_leaves(root->right);
    }
    
}

int main(){

// question 2 starts

    struct node *root;
    printf("sample tree for this question is \n");
    root = randomtree();
    inorder(root);
    count_leaves(root);
    printf( "\nthe no. of leafs in tree is %d",count1 );
    

    return 0;
}