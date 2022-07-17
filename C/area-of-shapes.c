#include <stdio.h>

int main(){
    int choice,r,l,b,bas,h;
    float ar1,ar2,ar3;
    printf("Enter the desired shape:1.Circle 2. Rectangle 3. Triangle");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("Enter the radius of circle");
        scanf("%d",&r);
        ar1=3.14*r*r;
        printf("Area of circle is:%f",ar1);
        break;
        
        
        case 2:printf("Enter the length and breadth of recangle");
        scanf("%d,%d",&l,&b);
        ar2=l*b;
        printf("Area of rectangle is:%f",ar2);
        break;
        
        case 3:printf("Enter the base and height of Triangle");
        scanf("%d,%d",&bas,&h);
        ar3=0.5*bas*h;
        printf("Area of triangle is:%f",ar3);
        break;
        
        default:printf("Enter a valid num");
        break;
    }
return 0;
}
