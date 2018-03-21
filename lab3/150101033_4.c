//MAYANK AGRAWAL
//ROLL NO. 150101033

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  
int count = 0;

#define max(x, y) (((x) > (y)) ? (x) : (y))

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

/*
 Diameter of a Binary search tree is max(d(v) + d(w) -2*LCA(v,w)). where d(v),d(w) are depths with respect to root.
 So this Diameter is the maximum length of path between any two leaves of a binary search tree.
 3 cases arise:
 1) Diameter includes only  left subtree path of binay tree.
 2) Diameter includes only  right subtree path of binary tree.
 3) Diameter contains path including root.

 so, Diameter is maximum of these three.
*/
// provides with height of each subtree
int getHeight(struct node *root) {
   if (root == NULL)
      return 0;

      // find the height of each subtree
      int lh = getHeight(root->left);
      int rh = getHeight(root->right);

      return 1 + max(lh,rh);
}

// compute tree diameter recursively 
int getDiameter(struct node *root) {
   if (root == NULL)
      return 0;

   // get height of each subtree
   int lh = getHeight(root->left);
   int rh = getHeight(root->right);

   // compute diameters of each subtree
   int ld = getDiameter(root->left);
   int rd = getDiameter(root->right);

   return max(lh+rh+1,max(ld,rd));
}

int main()
{
    struct node *root;
    printf("sample tree for this question is \n");
    root = randomtree();
    inorder(root);
    printf("\nDiameter of Tree is : %d ",getDiameter(root));
    printf("\n");
    return 0;

}

/* Time complexity  =   o(n^2)
 Note:- Root is at level 1.  */   