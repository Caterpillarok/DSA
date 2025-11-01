#include<stdio.h>

int Binary_search(int arr[],int key,int n){
    int low = 0;
    int high = n-1;
    
    
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==key)
            return mid;
        else if(key>arr[mid])
            low = mid+1;
        else
            high = mid -1;
        }
        return -1; 
}

int main(){

    int n,arr[100],key;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);

    printf("Enter the array in the sorted format\n");
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);}

    printf("Enter the element u want to search for\n");
    scanf("%d",&key);

    int result = Binary_search(arr,key,n);

    if(result == -1)
        printf("Element not found \n");
    else
        printf("Element found at postion %d",result);
    printf("\n");

    return 0;


}