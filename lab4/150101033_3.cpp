// mayank agrawal
// 150101033
// To complie type: g++ 150101033_3.cpp -std=c++11 in linux

#include <bits/stdc++.h>
#include <cstdlib> 
#include <cstdio>
#include <iostream>

using namespace std;

struct node{
	int row;
	int col;
	int value;
	struct node * right;
	struct node * down;
};

struct node *createnode(int row,int col,int value){
	struct node *temp = new struct node;
	temp->row = row;
	temp->col = col;
	temp->value = value;
	return temp;
}

class sparse_matrix{

	struct node *right;
	struct node *down;
	int row,col;

	public:

	sparse_matrix(int r,int c){   		//row or col value of 0 indicates the node is a pointer to a row or column.
		row = r;					
		col = c;
	    right = new struct node[c];
		down = new struct node[r];

		for(int i=0;i<r;i++){
			down[i].down = &down[(i+1)%r];
			down[i].right = &down[i];
			down[i].row = i;
			down[i].col = 0;
			down[i].value = -1;
			}
		for(int i=0;i<c;i++){
			right[i].right = &right[(i+1)%c];
			right[i].down = &right[i];
			right[i].row = 0;
			right[i].col = i;
			right[i].value = -1;
			}
		//pointer right[0] and down[0] are same struct node
		right[0].right = &right[1]; 
		right[0].down = &down[1];
		down[0] = right[0];
	}

	void insert(struct node *temp){
		int R = temp->row;
		int C = temp->col;

		struct node *tempC = &right[C];
		struct node *tempR = &down[R];

		while( (tempC->row)<R || (tempC->down)->row==0 ){   
			if((tempC->down)->row==0){
				 temp->down = tempC->down;  
				 tempC->down = temp;
				 break;
			}else if((tempC->down)->row > R){
				 temp->down = (tempC->down);
				 tempC->down = temp;
				 break;
			}else{
				tempC = tempC->down;
			}		
		}
		while( (tempR->col)<C || (tempR->right)->col==0 ){
			if((tempR->right)->col==0){
				 temp->right = tempR->right;  
				 tempR->right = temp;
				 break;
			}else if((tempR->right)->col > C){
				 temp->right = (tempR->right);
				 tempR->right = temp;
				 break;
			}else{
				tempR= tempR->right;
			}		
		}
	}

	void largest(){   
		int maximum=0;	 

		for(int i=1;i<row;i++){   
			if(down[i].right->col==0)			//if that row has no elements
				continue;
			struct node * temp = (&down[i])->right;

			while (temp->col!=0){
			 	if(temp->value > maximum)
			 		maximum = temp->value;

			 	temp = temp->right;
			 } 
		}
		printf("Maximum element in the matrix is : %d\n",maximum);
	}

	//The function to display the value of the matrix row-wise .
	void row_print(){   
		cout<<"\nDisplaying value row-wise : \n"; 
		for(int i=1;i<row;i++){   
			printf("value in row =>%d\n",i);
			struct node * temp = (&down[i])->right;
			while (temp->col!=0){
			 	printf("row: %d,Col: %d,value: %d\n",temp->row,temp->col,temp->value);
			 	temp = temp->right;
			 } 
		}
	}

};

int main(){  

	int r,c,k;
	printf("enter the no. of row, column:\n ");
	scanf("%d %d",&r,&c);
	printf("Enter the number of non -zero elments : ");
	scanf("%d",&k);

	int a[k][3],t,x,y,flag;
	srand(time(NULL));
	
	for(int i=0;i<k;i++){
		x = rand()%r + 1;
		y = rand()%c + 1;
		a[i][1]=x;
		a[i][2]=y;
		a[i][0]=rand()%1000;
		for(int j=0;j<i;j++){
			if( x==a[j][1] && y==a[j][2] ){
				j--;		// to remove those value of <i,j> which are already been used.
				break;
			}
		}
	}
   
    sparse_matrix m(r+1,c+1);	//m is the class object
    for(int i=0;i<k;i++){
        m.insert( createnode (a[i][1],a[i][2],a[i][0]) );
    }
    // function to print the elements row wise
    m.row_print();

    m.largest();
	return 0;
}