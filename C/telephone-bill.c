#include <stdio.h>

int main() {
    int call;
    float bill;
    printf("Enter the no. of calls done:");
    scanf("%d",&call);
    switch(call<=100){
        case 1:printf("Payable amount is Rs. 200");
        break;
        case 0:switch(call>100 && call<=150){
            case 1:bill = 200 + 0.6*(call-100);
            printf("Payable amount is Rs. %f",bill);
            break;
            
            case 0:switch(call>150 && call<=200){
                case 1: bill= 200 + 0.6*50+ 0.5*(call- 150);
                printf("Payable amount is: Rs. %f",bill);
                break;
                
                case 0:switch(call>200){
                    case 1:bill= 200 + 0.6*50+ 0.5*(50) + 0.4*(call - 200);
                    printf("Payable amount is: Rs. %f",bill);
                    break;
                    
                    case 0:printf("Enter a valid no. of calls");
                }
            }
        }
    }
    
    
    return 0;
}
