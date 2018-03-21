//MAYANK AGRAWAL
//ROLL NO. 150101033

#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
    int expo;
    struct node *link;
};

struct node *insert_s(struct node *start,int co,int ex){
    struct node *ptr,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->coef=co;
    tmp->expo=ex;
    if(start==NULL || ex > start->expo){
        tmp->link=start;
        start=tmp;
    }
    else{
        ptr=start;
        while(ptr->link!=NULL && ptr->link->expo >= ex)
            ptr=ptr->link;
        tmp->link=ptr->link;
        ptr->link=tmp;
    }
    return start;
}

struct node *create_poly(struct node *start,int n){
    int i,ex,co;
    
    for(i=1;i<=n;i++){
        printf("Enter coeficient for term %d : ",i);
        scanf("%d",&co);
        printf("Enter exponent for term %d : ",i);
        scanf("%d",&ex);
        start=insert_s(start,co,ex);
    }
    return start;
}

void display(struct node *ptr){
   
    while(ptr!=NULL){
        printf("(%dx^%d)", ptr->coef,ptr->expo);
        ptr=ptr->link;
        if(ptr!=NULL)
            printf(" + ");
        else
            printf("\n");
    }
}

void poly_mult(struct node *p1, struct node *p2,int n,int m){
    struct node *start3;
    struct node *p2_beg = p2;
    int a[1000]={0};
    int count;
    start3=NULL;
    while(p1!=NULL){
        p2=p2_beg;
        while(p2!=NULL)
        {
            a[p1->expo+p2->expo]+=p1->coef*p2->coef;
            p2=p2->link;
            count++;
        }
        p1=p1->link;
    }
    for(int i=0;i<1000;i++){
        if(a[i]!=0){
            start3=insert_s(start3,a[i],i);
        }

    }   
    printf("Multiplied polynomial is : ");
    display(start3);
}

int main( ){
    int m,n;
    struct node *start1=NULL,*start2=NULL;
   
    printf("Enter polynomial 1 :\n");
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    start1=create_poly(start1,n);

    printf("Enter polynomial 2 :\n");
    printf("Enter the number of terms : ");
    scanf("%d",&m);
    start2=create_poly(start2,m);

    printf("Polynomial 1 is :  ");
    display(start1);
    printf("Polynomial 2 is :  ");
    display(start2);
       
    poly_mult(start1, start2,n,m);

    return 0;
}