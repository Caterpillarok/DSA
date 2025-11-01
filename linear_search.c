#include<stdio.h>

int linear_search(int arr[],int n,int key){

    for(int i = 0;i<n;i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int n,key;

    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements of the array\n");
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enther the number you want to search for\n");
    scanf("%d",&key);

    int result = linear_search(arr,n,key);

    if(result == -1)
        printf("Element not found\n");
    else
        printf("Element found at postion %d ",result);
    printf("\n");
    
    return 0;


}