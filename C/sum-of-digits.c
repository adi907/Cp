#include <stdio.h>

int main() {
    int num,dig1,dig2,dig3,dig4,sum1;
    printf("Enter 4 digit number");
    scanf("%d",&num);
    dig1= num/1000;
    dig2= (num-(dig1*1000))/100;
    dig3=(num-(dig1*1000)-(dig2*100))/10;
    dig4=(num-(dig1*1000)-(dig2*100)-(dig3*10));
    sum1= dig1+dig2+dig3+dig4;
    printf("Answer is: %d", sum1);
    
    
    
    return 0;
}
