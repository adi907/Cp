// Approach: Iterate string. Ignore a blank space if no sign/no. has come uptil now. Mark the resp. sign flag if a sign comes. If already another sign/no. has come break. Calculate value if a no. comes(keep in mind if value exceed INT_MIN or INT_MAX return). Else break(incase alphabets come/space come up after enocuntering a sign/no.)
// Time complexity: O(N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    long long int ans=0LL;
    bool neg_flag=0;
    bool pos_flag=0;
    bool dig_start=0;

    for(int i=0;i<s.size();i++){
        if(!dig_start && !pos_flag && !neg_flag && s[i]==' '){
            continue;
        }else if(s[i]=='-'){
            if(pos_flag || dig_start ||neg_flag){
                break;
            }
            neg_flag=1;
        }else if(s[i]=='+'){
            if(neg_flag || dig_start || pos_flag){
                break;
            }
            pos_flag=1;
        }else if(s[i]>='0' && s[i]<='9'){
            dig_start=1;
            int num=s[i]-'0';
            ans=(long long int)((ans*10)+(num));
            
            if(ans>INT_MAX && neg_flag==1){
                return INT_MIN;
            }
            if(ans>INT_MAX){
                return INT_MAX;
            }
        }else{
            break;
        }
    }

    if(neg_flag==1){
        return (ans*-1);
    }
return (int)ans;
}
