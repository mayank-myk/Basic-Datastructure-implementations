#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int insertionsort (int a[] ,int n){
	int j,i,key,counter=1;

	for(j=1 ; j<n ;j++){
		key= a[j];
		i=j-1;

		while(i>=0 && a[i]>key){
			a[i+1]=a[i];
			counter++;
			i--;
		}
		a[i+1]=key;
	}
	for(j=0;j<n;j++){
		printf("%d ",a[j]);
	}
	printf("\n");
	return counter;
}

int insertionsort1 (int a[] , int n){

	int j,i,key,counter1=0,m,l,h,t;
	for(j=1 ; j<n ;j++){
		key=a[j];
		h=j-1;
		l=0;
		
		while( 1 ){
			m = (h + l ) / 2;
			if(l>=h){
				counter1++;
            	if(a[m]<key){
                	t= m+1;
                	break;
                }
            	else{
                	t= m;
                	break;
                }
        	}
        	if(a[m]>key && a[m-1]<key){
        		counter1+=2;
           	 	t=m;
           	 	break;
           	}
        	else if (a[m]<key && a[m+1]>key){
        		counter1+=2;
            	t=m+1;
            	break;
            }
        	else{
        		counter1++;
           	 	if(a[m]>key)
                	h = m-1;
            	else
                	l = m+1;
        	}
		}

		for(i=j-1;i>=t;i--){
			a[i+1]=a[i];
		}
		a[t]=key;
	}

	for(j=0;j<n;j++){
		printf("%d ",a[j]);
	}
	printf("\n");
	return counter1 ;
}

int main (){

	int a[1000],b[1000],n,i,q,p;
	printf("enter the input size \n");
	scanf("%d",&n);
	srand(time(NULL));

	for(i=0;i<n;i++){
		a[i]= ( rand() ) % 1000;
        b[i] = a[i];
	}
	q=insertionsort1(a,n);
	p=insertionsort (b,n);

	printf("\nno. of comparisons with binary search is %d and with normal search is %d ",q,p);
return 0;
}
