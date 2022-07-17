#include <stdio.h>
#include<math.h>

int main() {
    int a,b,c;
    float x,y,z;
    printf("For a given equation ax^2 + bx +c,enter a,b and c:");
    scanf("%d,%d,%d",&a,&b,&c);
    x=(b*b)-(4*a*c);
    y= (-b + sqrt(x))/2*a;
    z=(-b - sqrt(x))/2*a;
    printf("x= %f,%f",y,z);
    
    return 0;
}
