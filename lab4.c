#include<stdio.h>
#include<stdlib.h>

int nextMax(int array[],int n){
	int size=2*n;
	int temp=array[1];
	array[1]=0;
	int i=1;
	for( i=1;i<=size/2;){
		if(array[i*2]==temp){
			array[i*2]=0;
			i=i*2;
		}	
		else{
			array[i*2+1]=0;
			i=i*2+1;
		}	
	}
	
	while(1){
		if(i==0)
			break;
			
			
		if(i%2==0){
			if(array[i]>array[i+1])
				array[i/2]=array[i];
			else
				array[i/2]=array[i+1];	
			i=i/2;	
		}
		else{
			if(array[i]>array[i-1])
				array[i/2]=array[i];
			else
				array[i/2]=array[i-1];
			i=i/2;		
		}
		
	}
	
	return array[1];

}

void build(int array[],int n){
	int size=2*n;
	
	
	
	for(int i=size-1;i>=n;i-=2){
		if(array[i]>array[i-1])
			array[i/2]=array[i];
		else
			array[i/2]=array[i-1];	
	}
	
	
	if(n/2!=0)
	build(array,n/2);
	
	
}

int main(){
	int n;
	scanf("%d",&n);
	int size=2*n;
	int *array=(int *)malloc(size * sizeof(int) );
	
	for(int i=n;i<size;i++)
		scanf("%d",&array[i]);
		
		
	build(array,n);
	for(int i=1;i<size;i++)
		printf("%d ",array[i]);
		
	printf("nextmax %d \n",nextMax(array,n));		
}










