//MAYANK AGRAWAL 150101033
#include <stdio.h>
void mergesort(int arr[],int st,int en,int* k1){
	if(en-st>=1){
        *k1=*k1+1;
		mergesort(arr,st,(st+en)/2,k1);
		mergesort(arr,(st+en)/2+1,en,k1);
	}else{
	    *k1=*k1+1;
		return;
	}
	int i,j,tem[en-st+1],k=0,p;
	for(i=st,j=(st+en)/2+1;i<=(st+en)/2&&j<=en;){
		if(arr[i]>arr[j]){
			tem[k++]=arr[j++];
		}else{
			tem[k++]=arr[i++];
		}
		*k1=*k1+1;;
	}
	for(;i<=(st+en)/2;){
		tem[k++]=arr[i++];
	}
	for(;j<=en;){
		tem[k++]=arr[j++];
	}
	for(p=st;p<=en;p++){
		arr[p]=tem[p-st];
	}
}
int position(int a,int arr[],int st,int en,int * k1){
	int mid=(st+en)/2;
	if(st==en){
		if(arr[st]>a){
			return st;
		}else{
			return en+1;
		}
	}else if(arr[mid]<=a&&arr[mid+1]>=a){
	    *k1=*k1+1;
		return mid+1;
	}else if(arr[mid]>=a){
	    *k1=*k1+2;
		return position(a,arr,st,mid,k1);
	}else{
	    *k1=*k1+2;
		return position(a,arr,mid+1,en,k1);
	}
}
void binaryinsersionsort(int arr[],int size,int * k1){
	int i,j;
	for(i=1;i<size;i++){
		int k=arr[i];
		int pos=position(k,arr,0,i-1,k1);
		for(j=i-1;j>=pos;j--){
			arr[j+1]=arr[j];
		}
		arr[pos]=k;
	}
}
void thresholdvalue(){
	int i;
	int q=1,k2=0,k1;
	printf("for calculating threshold:\nwe take random arrays of size from 1 to 150 and print the no. of comparisions and print OK if binary insersion sort exceeds merge sort\nsize\tbinary\tmerge\n");
	for(;q<=150;q+=1){
        int arr1[q],arr2[q];
        int i,k=0;
        for(i=0;i<q;i++){
            arr1[i]=rand()%1000;
            arr2[i]=arr1[i];
        }
        binaryinsersionsort(arr1,q,&k);
        printf("%d\t",q);
        printf("%d\t",k);
        k1=k;
        k=0;
        mergesort(arr2,0,q-1,&k);
        printf("%d\t",k);
        if(k1>=k){
            printf("OK");
        }
        printf("\n");
	}
	printf("From the data we chose the threshold as 55\n");
}

void modifiedmergesort(int *arr,int st,int en,int * k1){
	if(en-st>=55){
        *k1=*k1+1;
		mergesort(arr,st,(st+en)/2,k1);
		mergesort(arr,(st+en)/2+1,en,k1);
	}else{
		int i,j;
		for(i=1+st;i<en+1;i++){
			int k=arr[i];
			int pos=position(k,arr,st,i-1,k1);
			for(j=i-1;j>=pos;j--){
				arr[j+1]=arr[j];
			}
			arr[pos]=k;
		}
	    *k1=*k1+1;
		return;
	}
	int i,j,tem[en-st+1],k=0,p;
	for(i=st,j=(st+en)/2+1;i<=(st+en)/2&&j<=en;){
		if(arr[i]>arr[j]){
			tem[k++]=arr[j++];
		}else{
			tem[k++]=arr[i++];
		}
		*k1=*k1+1;;
	}
	for(;i<=(st+en)/2;){
		tem[k++]=arr[i++];
	}
	for(;j<=en;){
		tem[k++]=arr[j++];
	}
	for(p=st;p<=en;p++){
		arr[p]=tem[p-st];
	}
}
void modifiedsort(int i){
	int arr[i],j,k=0;
	for(j=0;j<i;j++){
		//comment below statement
		arr[j]=rand()%1000;
		//uncomment below statement
		//scanf("%d",&arr[j]);
	}
	if(i<=54){
		binaryinsersionsort(arr,i,&k);
	}else{
		modifiedmergesort(arr,0,i-1,&k);
	}
	printf("%d\t%d\n",i,k);
	//if you want to print,uncomment this
	/*printf("sorted array:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}*/
}
int main(){
	thresholdvalue();
	int i=0;
	printf("random arrays of size 10,30,50,... has been taken and printed no. of comparision in modified sort\n");

	for(i=10;i<1000;i+=20){
		modifiedsort(i);
	}
	
	return 0;
}