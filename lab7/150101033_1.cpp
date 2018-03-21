//mayank agrawal
//150101033

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct set{
    int size;
    struct node *head;
    struct node *tail;
};

struct node{
    int data;
    struct set *rep ;
    struct node *next;
};
//initializing struct node abject and struct set object
struct node *make_set(int a) {
    struct set *newSet = new struct set;
    newSet->head = new struct node;
    newSet->tail = newSet->head;
    newSet->size=1;
    struct node *temp = newSet->head;
    temp->data = a;
    temp->rep = newSet;
    temp->next = NULL;
    return temp;
}
//returns the representative struct set of any struct node
struct set *find_set(struct node *a){
    return a->rep;
}

void *unions(struct node *x,struct node *y){
    struct set *a = find_set(x);        //find_set returns representative of any node
    struct set *b = find_set(y);

    if (a->size > b->size) {
        a->size=a->size + b->size;
        a->tail->next=b->head ;         //combining smaller set into bigger set
        a->tail = b->tail;
        struct node *temp=b->head;      //changing representative pointer of all elements of smaller 
        while(temp){                    //set to that of bigger set
            temp->rep= a;
            temp = temp->next;
        }
    }
    else{
        b->size =a->size + b->size ;
        b->tail->next=a->head;
        b->tail = a->tail;
        struct node *temp=a->head ;
        while(temp) {
            temp->rep= b;
            temp = temp->next;
        }
    }
}
//function to print the whole list
void pprint(struct node **arr,int arr1[],int k){
    int i,j,check[100]={0} ;
    cout << endl;
    for(i=0;i<k;i++){
        j=arr1[i];
        if(check[j]==0){
            struct node *temp=arr[j];
            struct set *temp1=temp->rep;
            struct node *temp2=temp1->head;
            while(temp2){
                cout << temp2->data << "  " ;
                check[temp2->data]=1;
                temp2 = temp2->next;
            }
            cout << endl;
        }
    }
    cout <<endl;
}

int main(){
    int k,j,n=0;
    cout<< "Input the value of k:  ";
    cin >> k ;
    int arr1[k];
    struct node ** arr=new struct node* [100];   //array to store all the struct node according to index 
    for(int i=0;i<k;i++){
        cout << "input the data (between 0 to 99):" ;
        cin >> j;
        arr[j] = make_set(j);
        arr1[i]=j;      //array to store value of each node
    }

    while(1){
        int m,a,b,c;
        cout << "1 for union,   2 for find_set,   3 for exit"  << endl;  
        cin >> m ;
        switch(m){
            case 1:
                cout << "type the number whose union you want to find" << endl;
                cin >> a >> b;
                unions(arr[a],arr[b]);
                pprint(arr,arr1,k);
                break;

            case 2:
                cout << "type the number whose find_set you need" << endl;
                cin >> c ;
                struct set *y;
                y=find_set(arr[c]);
                cout << "the set representative is "<< y->head->data << endl;
                break;

            default: exit(0);       
        }
    }
return 0;
}




