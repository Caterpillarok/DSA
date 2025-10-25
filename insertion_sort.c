#include<stdio.h>

void insertion_sort(int arr[],int n){
    int key,j; 

    for(int i = 1;i<n;i++){
        key = arr[i];
        j = i-1;

        while(j >=0 & arr[j]>key){
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void main(){
    int n;


    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter the elements of the array\n");

    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("The array is\n");
      for(int i =0;i<n;i++)
         printf("%d",arr[i]);
    
    printf("\n");

    printf("The sorted array is \n");

    insertion_sort(arr,n);

    printf("The sorted array is\n");
    for(int i =0;i<n;i++)
         printf("%d",arr[i]);
    printf("\n");


}


