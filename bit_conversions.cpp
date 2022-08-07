#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int bin2dec(int n){
    int x=1;
    int y;
    int ans=0;
    while(n>0){
        y=n%10;
        ans+=x*y;
        x*=2;
        n/=10;
    }
    return ans;
}

int oct2dec(int n){
    int x=1;
    int y;
    int ans=0;
    while(n>0){
        y=n%10;
        ans+=x*y;
        x*=8;
        n/=10;
    }
    return ans;    
}

int hex2dec(string s){
    int x=1;
    int y,ans=0;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        if(s[i]>='0'&& s[i]<='9'){
            ans+=x*(s[i]-'0');
        }else if(s[i]>='A' && s[i]<='F'){
            ans+=x*(s[i]-'A'+10);
        }
        x*=16;
    }
return ans;
}

int dec2bin(int n){
    int ans=0;
    int x=1;
    while(x<=n){
        x*=2;
    }x/=2;

    while(x>0){
        int dig;
        dig=n/x;
        n-=dig*x;
        x/=2;
        ans=ans*10+dig;
    }

return ans;
}

int dec2oct(int n){
    int ans=0;
    int x=1;
    while(x<=n){
        x*=8;
    }x/=8;

    while(x>0){
        int dig;
        dig=n/x;
        n-=dig*x;
        x/=8;
        ans=ans*10+dig;
    }

return ans;
}

string dec2hex(int n){
    int x=1;
    string ans="";
    while(x<=n){
        x*=16;
    }x/=16;
    while(x>0){
        int dig;
        dig=n/x;
        n-=dig*x;
        x/=16;
        if(dig<=9){
            ans+=to_string(dig);
        }else{
            char c;
            c=(dig-10)+'A';
            ans.push_back(c);
        }
    }
return ans;
}
int main()
{
    cout<<"\t\t****WELCOME TO NUMBER SYSTEM CONVERTOR****"<<endl;
    cout<<"1. Binary to Decimal";
    cout<<"\n2. Octal to Decimal";
    cout<<"\n3. Hexadecimal to Decimal";
    cout<<"\n4. Decimal to Binary";
    cout<<"\n5. Decimal to Octal";
    cout<<"\n6. Decimal to Hexadecimal";
    cout<<"\n\nEnter your choice :";
    int choice;
    int n;
    string str;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"\t\n*Binary to Decimal Convertor*"<<endl;
        cout<<"Enter Binary number:";
        cin>>n;
        cout<<"\nEquivalent Decimal number is: "<<bin2dec(n);
        break;
    case 2:
        cout<<"\t\n*Octal to Decimal Convertor*"<<endl;
        cout<<"Enter Octal number:";
        cin>>n;
        cout<<"\nEquivalent Decimal number is: "<<oct2dec(n);
        break;
    case 3:
        cout<<"\t\n*Hexadecimal to Decimal Convertor*"<<endl;
        cout<<"Enter Hexadecimal number:";
        cin>>str;
        cout<<"\nEquivalent Decimal number is: "<<hex2dec(str);
        break;
    case 4:
        cout<<"\t\n*Decimal to Binary Convertor*"<<endl;
        cout<<"Enter Decimal number:";
        cin>>n;
        cout<<"\nEquivalent Binary number is: "<<dec2bin(n);
        break;
    case 5:
        cout<<"\t\n*Decimal to Octal Convertor*"<<endl;
        cout<<"Enter Decimal number:";
        cin>>n;
        cout<<"\nEquivalent Octal number is: "<<dec2oct(n);
        break;
    case 6:
        cout<<"\t\n*Decimal to Hexadecimal Convertor*"<<endl;
        cout<<"Enter Decimal number:";
        cin>>n;
        cout<<"\nEquivalent Hexadecimal number is: "<<dec2hex(n);
        break;
    default:
        cout<<"!!Enter a valid choice code given from options above!!";
        break;
    }
return 0;
}
