/*
  Name:mayank agrawal
  Roll no.: 150101033
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n;

void push(int *data,int *p,int k)
{
	if(*p<n)
	{
		data[*p]=k;
		(*p)++;
	}
}

void pop(int* data,int *p)
{
	if(*p!=0)
	{
		(*p)--;
		data[*p]=0;
	}
}

void print_span(int* data,int *p)
{
	int *p2,*p3,k;
	k=*p;
	int span[k],arr[k],sub[k],end_arr=0,end_sub=0,i;
	p2=&end_arr,p3=&end_sub;
	span[0]=1;
	push(arr,p2,data[0]);
	push(sub,p3,0);
	for(i=1;i<k;i++)
	{
		while(end_arr!=0 & arr[end_arr-1]<=data[i])
		{
			pop(arr,p2);
			pop(sub,p3);
		}
		if(end_arr==0)
			span[i]=i+1;
		else span[i]=i-sub[end_sub-1];
		push(arr,p2,data[i]);
		push(sub,p3,i);
	}
	for(i=0;i<k;i++)
	{
		printf("%d)\t%d\t%d\n",i+1,data[i],span[i]);
	}
	printf("\n");
}

int main()
{
	int i=1,end=0,k;
	int *data,*p1;
	p1=&end;
	printf("Size of Stack:");
	scanf("%d",&n);
	data=(int*)malloc(n*sizeof(int));
	while(i)
	{
		printf("New Stack: ");
		for(k=0;k<end;k++)
			printf("%d\t",data[k]);
		printf("\n0)Span Array Calculation\n1)Push an Element\n2)Pop an Element\n\nChoice:");
		scanf("%d",&i);
		switch(i)
		{
			case 0:print_span(data,p1);break;
			case 1:{
					printf("enter the value u want to push:");
					scanf("%d",&k);
					push(data,p1,k);
					}break;
			case 2:pop(data,p1);;break;
		}
	}
	return 0;
}
