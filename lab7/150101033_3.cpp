//mayank agrawal
//150101033
// GIVE THE INPUT IN THE SAME WAY AS MENTIONED IN THE QUESTION WITH COMMAS & FULL STOP AT LAST 
// OTHERWISE IT WILL SHOW SEGMENTATION FAULT
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
//returns the representative element of any member
int find_set(int parent[],int i){
    if(parent[i]!= i){
         parent[i]= find_set(parent,parent[i]);
    }
    return parent[i];
}

void unions(int parent[],int a,int b){
    parent[a]=b;                //changing representative element of first occuring set to that of second occuring set
}
//initializing struct node abject 
void make_set( int parent[],int i){
    parent[i]=i;
}

int main(){
    int m=0,n=0,p;
    cout << "input the string WITH COMMAS separated value & FULL STOP AT LAST " << endl;
    cout << "ensure n<10(number of  insert calls) and at any moment of input m(no. of extract_min) is <=n" <<endl; 
    string str;
    cin >> str ;
    int len=str.length();           //for now please ensure n <10 i.e. n>=1 to n<=9
    int arr1[100];
    for(int i=0;i<len;i+=2){
        if(str[i]=='E'){
            m++;
        }
        if(str[i]!='E'){
            p=str[i]-'0';
            arr1[p]=m+1;
        }
    }
    len=(len)/2;
    n=len - m;
    int parent[m+2];
    int extracted[m];
    //following the same steps as given in cormen
    for(int i=1;i<=n;i++){
        make_set(parent,i);
    }
    for(int i=1;i<=n;i++){
        int flag=0;
        int j=find_set(parent,arr1[i]);
        if(j!=m+1){
            extracted[j]=i;
            for(int k=j+1;k<=m+1;k++){
                if(k==find_set(parent,k)){
                    unions(parent,j,k);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << extracted[i] << "    "  ;   
    }
return 0;
}
