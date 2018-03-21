/*
  Name:mayank agrawal
  Roll no.: 150101033
*/
#include <stdio.h>
 
void Span(int stockprice[], int n, int S[])
{
   S[0] = 1;
 
   //calculating the span ny comparing previous values
   for (int i = 1; i < n; i++)
   {
      // Initialize span value
      S[i] = 1; 

      // move left till the next element on left is smaller than stockprice[i]
      for (int j = i-1; (j>=0) && (stockprice[i]>=stockprice[j]); j--)
          S[i]++;
   }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
}
 
int main()
{   
    int n;
    printf("input the size of inputs\n");
    scanf("%d",&n);
    int S[n],stockprice[n];

    printf("enter the inputs\n");
    for(int i=0;i<n;i++){
        scanf("%d",&stockprice[i]);
    }
    
    Span(stockprice, n, S);
 
    // print the calculated span values
    printArray(S, n);
 
    return 0;
}