// Approach: Each time add the corr. numeric to ans if current index value greater than next one. Subtract if current's numeric value smaller than next one
// Time complexity: O(N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int intNum(char c){
    switch(c){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return 0;
            break;
    }
}

int romanToInt(string s) {
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(i==s.size()-1){ //last symbol always gets added as no next element to compare to
            ans+=intNum(s[i]);
            return ans;
        }else{
            int curr=intNum(s[i]);
            int next=intNum(s[i+1]);
            if(curr<next){  
                ans-=curr;
            }else{
                ans+=curr;
            }
        }
    }
return ans;
}