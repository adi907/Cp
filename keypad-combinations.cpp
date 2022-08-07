#include<bits/stdc++.h>
using namespace std;
//array of string type
string keypadArr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    char ch=input[0];
    string code=keypadArr[ch-'0'];
    for(int i=0;i<code.length();i++){
        keypad(input.substr(1),output+code[i]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif
    string str;
    cin>>str;
    string ans="";
    cout<<"All possible combinations of words from given keypad input "<<str<<" are:"<<endl;
    keypad(str,ans);
    
return 0;
}
