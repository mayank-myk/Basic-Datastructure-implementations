//MAYANK AGRAWAL 150101033
#include <stdio.h>
#include <stdlib.h>
// Global counter variable
int count=0;

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
        count++;
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

int main(){
    int arrsize, i;

    printf("Enter the input size: ");
    scanf("%d",&arrsize);

    int arr[arrsize];

    //randomizing the array and printing it
    randomizeArray(arr, arrsize);

    printf("Random Array:\n");
    for(i=0;i<arrsize;i++){
        printf("%d ",arr[i]);
    }

    //applying merge sort to the array by passing pointer to the array
    merge_Sort(arr, 0,arrsize-1);
    
    //printing sorted array
    printf("\nMerge Sorted Array:\n");
    for(i=0;i< arrsize;i++){
        printf("%d ",arr[i]);
    }

    printf("\nNumber of comparisons made between elements of the array: %d\n",count);
    return 0;
}
