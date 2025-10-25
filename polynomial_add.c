#include<stdio.h>

void main(){
    int exp1[10], exp2[10];
    int coeff1[10], coeff2[10];
    int res_coef[10], res_exp[10];
    int n1,n2;
    int i,j,k;

    printf("Enter the number of terms in the first polynomial\n");
    scanf("%d",&n1);

    printf("Enter the coefficient and exponent of the first polynomial respectively(descending order)\n");
    for(int i = 0;i<n1;i++){
        scanf("%d %d",&coeff1[i],&exp1[i]);
    }

    printf("Enter the number of elements in the second polynomial\n");
    scanf("%d",&n2);

    printf("Enter the coefficient and exponents of the 2nd polynomial\n");
    for(int i = 0;i<n2;i++)
        scanf("%d %d",&coeff2[i],&exp2[i]);


    i=j=k=0;

while(i<n1 && j<n2){
    if(exp1[i] == exp2[j]){
        res_exp[k] = exp1[i];
        res_coef[k] = coeff1[i] + coeff2[j];
        i++,j++,k++;
    }
    else if(exp1[i] > exp2[j]){
        res_exp[k] = exp1[i];
        res_coef[k] = coeff1[i];
        i++,k++;
    }
    else{
        res_exp[k] = exp2[j];
        res_coef[k] = coeff2[j];
        j++,k++;
    }
}

while(i<n1){
    res_exp[k] = exp1[i];
    res_coef[k] = coeff1[i];
    i++,k++;
    
}
while(j<n2){
     res_exp[k] = exp2[j];
     res_coef[k] = coeff2[j];
     j++,k++;
 
}
printf("The sum is \n");
for(i=0;i<k;i++){
    printf("%dx^%d",res_coef[i],res_exp[i]);
        if(i!=k-1)
            printf("+");
}


}
