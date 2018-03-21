
//MAYANK AGRAWAL
//150101033

//INSERT AND PRINT FUNCTION ARE WORKING FINE
// BUT EXTRACT_MIN IS DELETING THE WHOLE BRANCH
//DUE TO ITME PROBLEM I COULDN'T FINISH PROPERLY

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int count = 1;
struct node * H = NULL;
struct node *Hr = NULL;
 
struct node {
    int n;
    int degree;
    struct node* parent;
    struct node* left_most;
    struct node* right;
};

struct node* make_heap() {
    struct node* np;
    np = NULL;
    return np;
}

struct node* create_node(int k) {
    struct node* p;//new node;
    p = (struct node*) malloc(sizeof(struct node));
    p->n = k;
    return p;
}

// Function to Join two binomial Tree
int link(struct node* y, struct node* z) {
    y->parent = z;
    y->right = z->left_most;
    z->left_most = y;
    z->degree = z->degree + 1;
}

struct node* merge(struct node* H1, struct node* H2) {
    struct node* H = make_heap();
    struct node* y;
    struct node* z;
    struct node* a;
    struct node* b;
    y = H1;
    z = H2;
    if (y != NULL) {
        if (z != NULL && y->degree <= z->degree)
            H = y;
        else if (z != NULL && y->degree > z->degree)
            /* need some modifications here;the first and the else conditions can be merged together!!!! */
            H = z;
        else
            H = y;
    } else
        H = z;
    while (y != NULL && z != NULL) {
        if (y->degree < z->degree) {
            y = y->right;
        } else if (y->degree == z->degree) {
            a = y->right;
            y->right = z;
            y = a;
        } else {
            b = z->right;
            z->right = y;
            z = b;
        }
    }
    return H;
}

struct node* unions(struct node* H1, struct node* H2) {
    struct node* prev_x;
    struct node* next_x;
    struct node* x;
    struct node* H = make_heap();
    H = merge(H1, H2);
    if (H == NULL)
        return H;
    prev_x = NULL;
    x = H;
    next_x = x->right;
    while (next_x != NULL) {
        if ((x->degree != next_x->degree) || ((next_x->right != NULL)
                && (next_x->right)->degree == x->degree)) {
            prev_x = x;
            x = next_x;
        } else {
            if (x->n <= next_x->n) {
                x->right = next_x->right;
                link(next_x, x);
            } else {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->right = next_x;
                link(x, next_x);
                x = next_x;
            }
        }
        next_x = x->right;
    }
    return H;
}

struct node* insert(struct node* H, struct node* x) {
    struct node* H1 = make_heap();
    x->parent = NULL;
    x->left_most = NULL;
    x->right = NULL;
    x->degree = 0;
    H1 = x;
    H = unions(H, H1);
    return H;
}

int DISPLAY(struct node* H) {
    struct node* p;
    if (H == NULL) {
        printf("\nHEAP EMPTY");
        return 0;
    }
    printf("\nTHE ROOT NODES ARE:-\n");
    p = H;
    while (p != NULL) {
        printf("%d", p->n);
        if (p->right != NULL)
            printf("-->");
        p = p->right;
    }
    printf("\n");
}

int reverse(struct node* y) {
    if (y->right != NULL) {
        reverse(y->right);
        (y->right)->right = y;
    } else {
        Hr = y;
    }
} 

struct node* find(struct node* H, int k) {
    struct node* x = H;
    struct node* p = NULL;
    if (x->n == k) {
        p = x;
        return p;
    }
    if (x->left_most != NULL && p == NULL) {
        p = find(x->left_most, k);
    }
    if (x->right != NULL && p == NULL) {
        p = find(x->right, k);
    }
    return p;
}

// Function to print the node rotated 90 degree cc
void showHeap(struct node * y, int degree){
        if(y->right)
            showHeap(y->right,degree);
        
        //printf("\n");
        
        if(y->left_most != NULL  || y->parent == NULL)
        {
            
           int i;
           for(i=0;i<6*degree + 4;i++ )
            printf(" ");
            printf("%d",y->n);
            
            if(y->left_most == NULL)
            printf("\n");
        }
        else{
            int i;
            for(i=0;i<4;i++)
            printf(" ");
            printf("%d\n",y->n);
        }
        if(y->left_most)
            {
            printf(" ");
            showHeap(y->left_most,degree+1);
            }
}

struct node* extract_min(struct node* H1) {
    //int min;
    struct node* t = NULL;
    struct node* x = H1;
    struct node *Hr;
    struct node* p;
    Hr = NULL;
    if (x == NULL) {
        printf("\nNOTHING TO EXTRACT");
        return x;
    }
    int min=x->n;
    p = x;
    while (p->right != NULL) {
        if ((p->right)->n < min) {
            min = (p->right)->n;
            t = p;
            x = p->right;
        }
        p = p->right;
    }
    if (t == NULL && x->right == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->right;
    else if (t->right == NULL)
        t = NULL;
    else
        t->right = x->right;
    if (x->left_most != NULL) {
        reverse(x->left_most);
        (x->left_most)->right = NULL;
    }
    H = unions(H1, Hr);
    return x;
}


void print(struct node *y){
    printf("Stucture of binomial heap (rotated 90 degrees ccwise):\n\n");
    if(!y){  
        printf("Heap Empty ");
        return;
    }
    showHeap(y,0);
}

int main() {
    int i, n, m, l;
    struct node* p;
    struct node* np;
    printf("enter no. of elements:  ");
    scanf("%d", &n);
    printf("enter the element:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &m);
        np = create_node(m);
        H = insert(H, np);
    }
    DISPLAY(H);
    while(1){
        printf("\n1)INSERT \n2)EXTRACT THE MINIMUM NODE\n3)print\n4)EXIT\n");
        scanf("%d", &l);
        switch (l) {
        case 1:
            {
                printf("\nENTER THE ELEMENT TO BE INSERTED:");
                scanf("%d", &m);
                p = create_node(m);
                H = insert(H, p);
                printf("\nNOW THE HEAP IS:\n");
                DISPLAY(H);
            }
            break;
        case 2:
            {
                printf("\nEXTRACTING THE MINIMUM NODE");
                p = extract_min(H);
                if (p != NULL)
                    printf("\nTHE EXTRACTED NODE IS %d", p->n);
                printf("\nNOW THE HEAP IS:\n");
                DISPLAY(H);   
            }
            break;
        case 3:
            {
                printf("\nprinting:\n");
                print(H);
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}