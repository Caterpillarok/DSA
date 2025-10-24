#include<stdio.h>

int partition(int arr[],int low,int high){
    int i = low-1;
    int pivot = array[high];

    for(int j =low;j<high;j++){
        if(arr[j]<= pivot)
        i++;
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void printt(){
    printf("The sorted elements are \n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("/n");
}