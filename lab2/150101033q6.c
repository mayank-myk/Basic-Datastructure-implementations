/*
  Name:mayank agrawal
  Roll no.: 150101033
*/
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node* next;
};
 
void push(struct node** head1, int newdata)
{
    struct node* node1 = (struct node*) malloc(sizeof(struct node));
 
    //fill the new node
    node1->data  = newdata;
    node1->next = (*head1);
 
    //now head points to the new node
    *head1 = node1;
}
 
int findloop(struct node *input)
{
    struct node  *a = input, *b = input;
  
    while (a && b && b->next ){

        //pointer a moves by one node and
        //pointer b moves by two nodes
        a = a->next;
        b = b->next->next;
        if (a == b)
        {
           return 1;
        }

    }
    return 0;
}

int main()
{
    struct node* head = NULL;
 
    printf("enter the five inputs\n");
    int d,i;

    for(i=0 ; i<4 ; i++){
        scanf("%d ",&d);
        push(&head,d);
    }

    if(findloop(head)){
        printf("loop found\n");
    }
    else printf("no loop found\n");
 
    /* Creating a loop for testing */
    head->next->next->next->next = head;
    if(findloop(head)){
        printf("loop found, test successful \n");
    }
    else printf("no loop found\n");

    return 0;
}