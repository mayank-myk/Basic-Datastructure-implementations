//MAYANK AGRAWAL
//ROLL NO. 150101033

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  
int count = 0;

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

//function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
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

/* It is a bottom up approach for finding LCA. We traverse from the bottom, 
and once we reach a node which matches one of the two nodes, we pass it up to its parent. 
The parent would then test its left and right subtree if each contain one of the two nodes.
 If yes, then the parent must be the LCA and we pass its parent up to the root. 
 If not, we pass the lower node which contains either one of the two nodes 
 (if the left or right subtree contains either p or q), or NULL 
 (if both the left and right subtree does not contain either p or q) up.*/

 struct node *LCA(struct node *root, int p, int q) {

  if (!root) return NULL;
  if (root->key == p || root->key == q) return root;
  struct node *left = LCA(root->left, p, q);
  struct node *right = LCA(root->right, p, q);
  if (left && right) return root;  // if p and q are on both sides
  return left ? left : right;  // either one of p,q is on one side OR p,q is not in L&R subtrees
  // Time Complexity : O(n) ,because all the nodes are visited exactly once.
}

int main(){

    struct node *root,*temp;
    printf("sample tree for this question is \n");
    root = randomtree();
    inorder(root);
    int p,q;
    printf("\nenter the numbers whose common ancestor you want to find: ");
    scanf("%d %d",&p,&q);
    temp=LCA(root,p,q);
    printf("the common ancestor is %d",temp->key);

    return 0;
}
// Time Complexity : O(n)
// as the recursion function created visits each and every node once and takes time proportional to n where n is the number of nodes
//hence the time complexity is linear