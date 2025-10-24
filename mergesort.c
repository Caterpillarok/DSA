#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right -mid ;

    int L[n1];
    int R[n2];

    for(int i =0;i<n1;i++){
        L[i] = arr[left+i];
    }for(int j =0;j<n2;j++){
        R[i] = arr[mid+1+j];
    }
    int i = int j = 0;
    int k = left
    while(i<n1 && j<n2)
        if(L[i]<=R[j]){
            arr[k++] = L[i++];
        }else 
            arr[k++] = R[j++];

    while(i<n1)
        arr[k++] = L[i++];
    while(j<n2)
        arr[k++] = L[j++];
}

void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid = left + (right - lefft)/2 ;

        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}