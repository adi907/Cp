// Approach: Calculate revisions of both before '.'. Compare. If 1 is exhausted still check while keeping the exhausted's revision as 0
// Time complexity: O(M+N) ; Space complexity: O(1)


// Faster approach(gives TLE for big cases)
#include<bits/stdc++.h>
using namespace std;

int compareVersion(string v1, string v2){
    int i=0;
    int j=0;

    while(i<v1.size() && j<v2.size()){
        // num for version 1
        string num1="";
        while(i<v1.size()){
            char ch=v1[i];
            i++;
            if(ch=='.'){
                break;
            }
            num1+=ch;
        }

        // num for version 1
        string num2="";
        while(j<v2.size()){
            char ch=v2[j];
            j++;
            if(ch=='.'){
                break;
            }
            num2+=ch;
        }

        int a=stoi(num1);
        int b=stoi(num2);
        if(a<b){
            return -1;
        }
        if(a>b){
            return 1;
        }
    }

    while(i<v1.size()){
        int b=0;
        int a;
        string num1="";
        while(i<v1.size()){
            char ch=v1[i];
            i++;
            if(ch=='.'){
                break;
            }
            num1+=ch;
            a=stoi(num1);
        }
        if(a>b){
            return 1;
        }
    }

    while(j<v2.size()){
        int a=0;
        int b;
        string num2="";
        while(j<v2.size()){
            char ch=v2[j];
            j++;
            if(ch=='.'){
                break;
            }
            num2+=ch;
            b=stoi(num2);
        }
        if(b>a){
            return -1;
        }
    }

return 0;
}


// Alt approach(long long int - better for bigger numbers)
int compareVersion(string v1, string v2) {
    int i=0;
    int j=0;

    while(i<v1.size() && j<v2.size()){
        // num for version 1
        long long int a=0LL;
        long long int b=0LL;
        while(i<v1.size()){
            char ch=v1[i];
            i++;
            if(ch=='.'){
                break;
            }
            a=a*10+1LL*(ch-'0');
        }
        // num for version 1
        string num2="";
        while(j<v2.size()){
            char ch=v2[j];
            j++;
            if(ch=='.'){
                break;
            }
            b=b*10+1LL*(ch-'0');
            
        }
        if(a<b){
            return -1;
        }
        if(a>b){
            return 1;
        }
    }

    while(i<v1.size()){
        long long int b=0LL;
        long long int a=0LL;
        string num1="";
        while(i<v1.size()){
            char ch=v1[i];
            i++;
            if(ch=='.'){
                break;
            }
            a=a*10+1LL*(ch-'0');
        }
        if(a>b){
            return 1;
        }
    }

    while(j<v2.size()){
        long long int a=0LL;
        long long int b=0LL;
        string num2="";

        while(j<v2.size()){
            char ch=v2[j];
            j++;
            if(ch=='.'){
                break;
            }
            b=b*10+1LL*(ch-'0');
        }
        if(b>a){
            return -1;
        }
    }

return 0;
}