#include <stdio.h>

int main(){
    float cel,far,cel1,far1;
    printf("\nEnter temperature in celsius:");
    scanf("%f", &cel);
    far1=(9*cel/5)+32;
    printf("Given temperature in farhaneits is: %f",far1);
    printf("\nEnter temperature in farheneit:");
    scanf("%f", &far);
    cel1=(far-32)*5/9;
    printf("Given temperature in celsius is: %f",cel1);
return 0;
}
