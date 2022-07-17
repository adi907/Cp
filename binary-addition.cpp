//Adding Two binary numbers to return a binary number Create input.txt and output.txt before running

#include<iostream>
using namespace std;

int reverse(int x){
    int rev=0,dig;
    while(x>0){
        dig=x%10;
        rev=rev*10+dig;
        x/=10;
    } 
return rev;
}

int add_bin(int a,int b){
    int ans=0;
    int carry=0;

    while(a>0 && b>0){
        if(a%2==0 && b%2==0){
            ans=ans*10+carry;
            carry=0;
        }
        else if(a%2==0 && b%2==1||a%2==1 && b%2==0){
            if(carry==1){
                ans=ans*10+0;
                carry=1;
            }else{
                ans=ans*10+1;
                carry=0; 
            }
        }else{
            ans=ans*10+carry;
            carry=1; 
        }
    a/=10;
    b/=10;
    }
    while(a>0){
        if(carry==1){
            if(a%2==1){
                ans=ans*10+0;
                carry=1; 
            }else{
                carry=0;
                ans=ans*10+1;
            }
        }else{
            ans=ans*10+(a%2);
        }a/=10;
    }
    while(b>0){
        if(carry==1){
            if(b%2==1){
                ans=ans*10+0;
                carry=1; 
            }else{
                carry=0;
                ans=ans*10+1;
            }
        }else{
            ans=ans*10+(b%2);
        }b/=10;
    } 
    if(carry==1){
        ans=ans*10+1;//this gives ans in reverse order   
    }
    ans=reverse(ans);
return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif

    int a,b;
    cin>>a>>b;
    cout<<add_bin(a,b);
return 0;
}
