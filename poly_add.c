#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff,int power){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> coeff = coeff;
    newnode -> power = power;
    newnode -> next = NULL;
    return newnode;
}

struct Node* insertAtEnd(struct Node* head,int coeff,int power){
    struct Node* newnode = createNode(coeff,power);

    if(head == NULL)
        return newnode;

    struct Node * temp = head;
    while(temp->next!=NULL){
        temp = temp -> next;
    }
    temp->next = newnode;
    return head;

}

struct Node* polyadd(struct Node* poly1,struct Node* poly2){
    struct Node* result = NULL;
    int coeff;
    int power;

    while(poly1 != NULL && poly2 != NULL){
        if(poly1->power > poly2 ->power){
            result = insertAtEnd(result,poly1->coeff,poly1->power);
            poly1 = poly1->next;
        }
        else if(poly2-> power > poly1 -> power){
            result = insertAtEnd(result,poly2->coeff,poly2->power);
            poly2 = poly2->next;
        }
        else{
            result = insertAtEnd(result,poly1->coeff + poly2->coeff,poly1->power);
            poly1 = poly1 -> next;
            poly2 = poly2-> next;
        }
    }
    while(poly1!=NULL){
        result = insertAtEnd(result,poly1->coeff,poly1->power);
        poly1 = poly1 ->next;
    }
        while(poly2!=NULL){
        result = insertAtEnd(result,poly2->coeff,poly2->power);
        poly2 = poly2 ->next;
    }
    return result;
}

void display(struct Node* poly){
    while(poly!=NULL){
       printf("%dx^%d", poly->coeff,poly->power);
       if(poly->next!=NULL)
            printf(" + ");
        poly = poly->next;
       }
        printf("\n");
}

int main(){
    struct Node* poly1 =NULL;
    struct Node* poly2 = NULL;
    struct Node * sum = NULL;
    int coeff,power,n1,n2;

    printf("Enter the number of terms in the first polynomial: \n");
    scanf("%d",&n1);
    printf("Enter elements of the first polynomial in the descending order\n");
    printf("Enter the coefficients and power:\n ");
    for(int i =0;i<n1;i++){
        
        scanf("%d %d",&coeff,&power);
        poly1 = insertAtEnd(poly1,coeff,power);
        
    }
   printf("Enter the number of terms in the second polynomial:\n");
   scanf("%d",&n2);

   printf("Enter the elements of the second polynomial in the descending order:\n ");
   printf("Enter the coefficient and power respectively\n");
   for(int i = 0;i<n2;i++){
   
    scanf("%d %d",&coeff,&power);
    poly2 = insertAtEnd(poly2,coeff,power);
   }
   printf("The first polynomiial is: ");
   display(poly1);

   printf("The second polynomial is: ");
   display(poly2);

   printf("The sum is : ");
   sum = polyadd(poly1,poly2);

   display(sum);
   return 0;

}