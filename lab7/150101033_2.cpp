//mayank agrawal
//150101033

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int k;
//returns the representative element of any member
int find_set(int parent[],int i){
    if(parent[i]!= i){
         parent[i]= find_set(parent,parent[i]);
    }
return parent[i];
}
//function to print the whole list
void pprint(int parent[]){
    int check[k]={0} ;
    cout << endl;
    for(int i=0;i<k;i++){
        if(check[i]==0){
            for(int j=0;j<k;j++){
                if(check[j]==0){
                    if( i == find_set(parent,j) ){
                        cout << j<< "  " ;
                        check[j]=1;
                    }
                }
            }
            cout << endl;
        }
    }
    cout <<endl;
}

void unions(int parent[], int rank[],int a,int b){
    int root_a = find_set(parent,a);         //find_set returns representative of any element
    int root_b = find_set(parent,b);
    if(rank[root_a] < rank[root_b]){         //combining smaller set into bigger set
        parent[root_a] = root_b ;            //changing representative element of smaller set to that of bigger set
    }                       
    else{
        parent[root_b] = root_a ;
    }
    if(rank[root_a] == rank[root_b]){
        rank[root_a]+=1;
    }
}
//initializing struct node abject 
void make_set( int arr[ ],int rank[],int parent[],int i){
    arr[i]=i;
    parent[i]=i;
    rank[i] = 0;
}

int main(){

    cout<< "Input the value of k:  ";
    cin >> k ;
    int arr[k];
    int rank[k];
    int parent[k];

    for(int i=0;i<k;i++){                //i had assumed the inputs to be {0,2,3,........k-1}
        make_set(arr,rank,parent,i);     //so use the union accordingly
    }

    while(1){
        int m,a,b,c,y;
        cout << "1 for union,   2 for find_set,   3 for exit"  << endl;  
        cin >> m ;
        switch(m){
            case 1:
                cout << "type two space separated number in range (0,1,2....k-1) whose union you want to find" << endl;
                cin >> a >> b;
                unions(parent,rank,a,b);
                pprint(parent);
                break;

            case 2:
                cout << "type the number in range (0,1,2....k-1) whose find_set you need" << endl;
                cin >> c ;
                y=find_set(parent,c);
                cout << "the set representative is "<< y << endl;
                break;

            default: exit(0);       
        }
    }

return 0;
}

