#include <stdio.h>

int main() {
    int num1,num2;
    float sum,dif,pr,div1;
    char op;
    printf("Enter the desired operation:");
    scanf("%c",&op);
    printf("Enter the 2 numbers:");
    scanf("%d,%d",&num1,&num2);
    
    switch(op){
        case '+':sum= num1 + num2;
        printf("Result after addition is:%f",sum);
        break;
        
        case '-':dif= num1 - num2;
        printf("Result after subtracion is:%f",dif);
        break;
        
        case '*':pr= num1 * num2;
        printf("Result after multiplication is:%f",pr);
        break;
        
        case '/':div1= num1 / num2;
        printf("Result after division is:%f",div1);
        break;
        
        default:printf("Enter a valid operation");
        break;
    }
    
    
    return 0;
}
