// Approach: Using recursion create all possible permutations. Then sort them and put them in a data structure
// Time complexity: O(n!*nlogn) ; Space complexity: O(n!)


// Approach: Total permuations=n! We know each term comes at 1st place (n!/n) times. Find out which term comes at 1st place by given k. Then send rest of string and reduced permutation no. to next iteration
// Time complexity: O(N*N) {N recursion calls each time calculating factorial} ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

// Better code(w/o recursion)

string kthPermutation(int n,int k){
    vector<int> num;
    string ans;
    int fac=1;

    for(int i=1;i<=n;i++){
        fac*=i;
        num.push_back(i);
    }
    k--;//as kth permutation means (k-1)perm.{1st per.=0th per.}

    int div;

    while(true){
        if(!num.size()){
            break;
        }
        div=k/(fac/n);
        k=k%(fac/n);
        fac/=n--;

        ans+=to_string(num[div]);
        num.erase(num.begin()+div);
    }

return ans;
}


/*
Worse code[O(n!*n)]: But my code :/

int factorial(int n){
    int ans=1;
    while(n !=1){
        ans*=n;
        n--;
    }
return ans;
}

void helper(string str,int k,string &res){
    if(!str.size()){
        return;
    }
    int n=str.size();
    int fac=factorial(n);
    int div1=fac/n;

    int div=k/div1;
    int rem=k%div1;

    res.push_back(str[div]);
    str=str.substr(0,div)+str.substr(div+1,n-div-1);
    helper(str,rem,res);
}
 
string kthPermutation(int n, int k) {
    string res="";
    string str;
    for(int i=1;i<=n;i++){
        str.append(to_string(i));
    }
    helper(str,k-1,res);
    //(k-1) bcz 24th permutation actually means 23rd permutation(1per. = 0th per.)
return res;
}
*/

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,k;
    cin>>n>>k;

    string ans;
    ans=kthPermutation(n,k);

    cout<<ans<<endl;
}