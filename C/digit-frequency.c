//2 approaches:-1. Basic Approach 2.Dynamically aloccated array

//Basic Approach

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[1000];
    scanf("%s",s);
    int arr[10]={0};
    int len;
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            arr[(int)s[i]-'0']++;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
