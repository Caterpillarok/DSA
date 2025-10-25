#include<stdio.h>

void selectionsort(int arr[],int n){
    int min_index,temp;

    for(int i =0;i<n;i++){
        min_index = i;
            for(int j = i+1;j<n;j++){
                if(arr[j]<arr[min_index])
                    min_index = j;
            }
    temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
}
}



void main(){

    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("The array is\n");

    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    printf("The sorted array is\n");
    selectionsort(arr,n);

    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");


}