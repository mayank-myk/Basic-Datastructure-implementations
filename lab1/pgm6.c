//MAYANK AGRAWAL 150101033
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//randomizing array function
void randomizeArray(int arr[], int arraysize){
    
    int i;
    //assigning random values to the array and putting a limit of 1000
    for(i=0;i<arraysize;i++){
        arr[i]=rand()%1000;
    }
}

void merge(int arr[], int min, int mid, int max){
    //initializing a temporary array to store the changes
    int i=min, j=mid+1, tempArray[max-min+1],k=0;
    //assigning minimum of the two sorted sub-arrays continually into the temporary array
    while(i<=mid && j<=max){
        if(arr[i]<=arr[j]){
            tempArray[k++]=arr[i++];
        }else{
            tempArray[k++]=arr[j++];
        }
    }
    //assigning the rest of the sub-array elements to the temp array
    while(i<=mid){
        tempArray[k++]=arr[i++];
    }
    while(j<=max){
        tempArray[k++]=arr[j++];
    }
    //updating original array through the temp array
    for(i=min,k=0;i<=max;i++,k++){
        arr[i]=tempArray[k];
    }
}

//merge sort function
void merge_Sort(int* arr, int min, int max){
    
    if(max>min){

        int mid=(min+max)/2;

        // Sort first and second halves
        merge_Sort(arr, min, mid);
        merge_Sort(arr, mid+1, max);

        merge(arr, min, mid, max);
    }
}

bool find(int arr1[], int arr2[], int arrsize, int m){
    //declaring required values
    int i, j, temp, min, max, mid;

    //initializing the boolean variable 
    bool ans=false;

    //for each element in array one
    for(i=0;i<arrsize;i++){
        //required value of b = m-a
        temp=m - arr1[i];
        //the binary search of b in array B
        min=0;
        max=arrsize;
        mid=arrsize/2;

        //binary search for required b in array two
        while(max>min && ans==false){
            //checking if b falls to the right or left of mid or is equal to it and updating mid, min and max values accordingly
            if(temp>arr2[mid]){
                min=mid+1;   
            }else if(temp<arr2[mid]){
                max=mid;
            }else{
                //if b is found
                ans = true;
                //printing a and b values
                printf("\nYes match found, a+b=(%d) for a=%d b=%d",m, arr1[i],temp);
            }
        mid=(min+max)/2;
        }
    }

    return ans;
}

int main(){
    int i,size,x;

    printf("Enter size for input ");
    scanf("%d",&size);

    //initializing arrays
    int A[size],B[size];

    //randomizing arrays
    randomizeArray(A, size);
    randomizeArray(B, size);

    //printing random arrays
    printf("\nRandom Array 'A':\n");
    for(i=0;i<size;i++){
        printf("%d ",A[i]);
    }

    printf("\nRandom Array 'B':\n");
    for(i=0;i<size;i++){
        printf("%d ",B[i]);
    }

     //input of the required number m
    printf("\n\nThe number 'm': ");
    scanf("%d",&x);

    //merge sorting both arrays in restricted time
    merge_Sort(A, 0,size-1);
    merge_Sort(B,0,size-1);

    //printing sorted arrays
    printf("\nMerge Sorted Array 'A':\n");
    for(i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\nMerge Sorted Array 'A':\n");
    for(i=0;i<size;i++){
        printf("%d ",B[i]);
    }

    //search function for a and b whose sum is m
    bool result = find(A, B, size-1, x);

    if(result==true){
        printf("\nexists\n");
    }else{
        printf("\nDoes not exist\n");
    }
    return 0;
}
