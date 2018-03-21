#include<stdio.h>
#include<stdlib.h>

void build_tournament_tree(int arr[],int n){
	int k;
	while(k){
		for(k=2*n-2;k>0;){
			arr[ (k-1)/2 ] = ( ( arr[k-1]>=arr[k] ) ? arr[k-1] : arr[k]  );
			k=k-2;
		}
	}
}

void next_max(int arr[],int n){
	int key = arr[0];
	arr[0]=0;
	int i=0;
	for( i=0;i<2*n-1;){
		if(arr[2*i+1]==key){
			arr[2*i+1] = 0;
			i=2*i+1;
		}
		else{
			arr[2*i+2]=0;
			i=2*i+2;
		}
	}
	while(1){
		if(i==0)
			break;

		if(i%2==0){
			arr[ (i-1)/2] = (arr[i]>arr[i-1]) ? arr[i]: arr[i-1];
			i=(i-1)/2;		
		}
		else{
			arr[i/2] = (arr[i]>arr[i+1]) ? arr[i] : arr[i+1] ;		
			i=i/2;	
		}
		
	}
}

int main(){
	int n,size;
	printf("input the array size: ");
	scanf("%d",&n);
	size = 2*n - 1;
	int arr[size];

	printf("enter the input greater than 0\n");
	for(int i=n-1 ; i < size; i++){
		scanf("%d",&arr[i]);
	}
	build_tournament_tree(arr,n);
	for(int i=0;i<size;i++){
		printf("%d ", arr[i] );
	}
	printf("\nthe winner is %d",arr[0]);

	next_max(arr,n);
	printf("\nthe modified tree is \n");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\nsecond winner is %d ",arr[0]);

	return 0;
}