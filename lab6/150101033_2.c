//mayank agrawal
//150101033
#include <stdio.h>
#include <limits.h>
 
int n, cost[10][10];

void prim(int pi[n],int key[n],int check[n]){
     
  for (int i=0;i< n-1;i++){
    int min = 10000, s; 

    for (int j= 0; j<n; j++){
      if (check[j] == 0 && key[j] < min){ //checking the unvisited array for minimum key
        min = key[j], s = j;              //s will be assigned the value of index with smallest key
      }
    } 

    check[s]= 1;        //mark index 's' in check array as 1 i.e visited
                              
    for (int k = 0;k<n;k++){        //searching for minm. cost neighbour of parent 's'
      if (cost[s][k] ==0)
        continue;
      else if(check[k] == 0 && cost[s][k] <  key[k]){
         pi[k]=s;
         key[k]=cost[s][k];
      }
    }

  }
  //prints the MST
  printf("Edge    cost\n");
  for (int i = 1; i < n; i++){
    printf("%d -> %d    %d \n",pi[i]+1,i+1,cost[i][pi[i]]);
  }
}

int main(){
   int i, j;
   printf("Enter the no. of vertices :");
   scanf("%d", &n);
 
   printf("Enter the costs of edges in matrix form :\n");
   for (i = 0; i < n; i++){
      for (j = 0; j < n; j++) {
         scanf("%d", &cost[i][j]);
      }
   }
   //pi is array for keeping track of parent index
   //check is array which keeps track of vertices as visited or not
   // Key is array which is used to choose minm. cost edge in cut
   int pi[n],key[n],check[n];
   for (int i = 0; i < n; i++){
      key[i] = 10000, check[i] = 0;
   }
   key[0] = 0;     //giving it a minimum value so that it can be choosed first
   pi[0]=-1;       //start vertex
   prim(pi,key,check);
 
   return 0;
}