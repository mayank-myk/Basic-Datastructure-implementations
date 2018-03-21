// mayank agrawal
// 150101033

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void flag(int **s1,char **s,int x,int y,int a,int b){
	// RECURSIVELY TRAVERSE AND MARK THE FLAG ARRAY AS 1
	if(x<0||x>a-1||y<0||y>b-1){
		return;
	}else if(s1[x][y]==1){
		return;
	}else{
		if(s[x][y]=='L'){
			s1[x][y]=1;
			flag(s1,s,x-1,y,a,b);
			flag(s1,s,x,y-1,a,b);
			flag(s1,s,x+1,y,a,b);
			flag(s1,s,x,y+1,a,b);
			return;
		}
	}
}

int dfs(char **s,int n,int len,int arr[]){

	int x2=arr[2];
	int y2=arr[3];
	int x1=arr[0];
	int y1=arr[1];
	int i,j;

	int **s1=(int**)malloc(n*sizeof(int *));
	for(i=0;i<n;i++){
		s1[i]=(int*)malloc(len*sizeof(int));//s1 is array for flagging the visited positions
	}
	for(i=0;i<n;i++){
		for(j=0;j<len;j++){
			s1[i][j]=0;
		}
	}
	flag(s1,s,x1,y1,n,len);
	if(s1[x2][y2]==1){
		return 1;
	}else{
		return 0;
	}
}
// it checks for the boundary condition
int test(char **s,int n,int len,int arr[]){

	int c=0,f=1,i;
	for(i=0;i<len;i++){
		if(s[0][i]=='L'){
			if(c<2){
				arr[2*c]=0;
				arr[2*c+1]=i;
			}else{
				f=0;
				break;
			}
			c++;
		}
		if(n!=1&&s[n-1][i]=='L'){
			if(c<2){
				arr[2*c]=n-1;
				arr[2*c+1]=i;
			}else{
				f=0;
				break;
			}
			c++;
		}
	}
	for(i=1;i<n-1;i++){
		if(s[i][0]=='L'){
			if(c<2){
				arr[2*c]=i;
				arr[2*c+1]=0;
			}else{
				f=0;
				break;
			}
			c++;
		}
		if(len!=1&&s[i][len-1]=='L'){
			if(c<2){
				arr[2*c]=i;
				arr[2*c+1]=len-1;
			}else{
				f=0;
				break;
			}
			c++;
		}
	}
	if(c!=2||f==0){
		return 0;
	}else{
		return 1;
	}
}

int main(){

	while(1){
		int a,b,i,j;
		scanf("%d %d",&a,&b);
		if(a==0&&b==0){
			break;
		}
		char **s=(char**)malloc(a*sizeof(char*));
		for(i=0;i<a;i++){
			s[i]=(char*)malloc((b+1)*sizeof(char));
		}
		for(i=0;i<a;i++){
				scanf("%s",s[i]);
		}
		int arr[4];
		if(test(s,a,b,arr)){
			if(dfs(s,a,b,arr)){
				printf("Submitted\n");
			}else{
				printf("Bad Luck!\n");
			}
		}else{
			printf("Bad Luck!\n");
		}
	}
	return 0;
}
