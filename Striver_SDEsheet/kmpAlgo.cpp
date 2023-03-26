// Approach: First compute the LPS table,keep i and len(if same store len in lps & move, else take 1 step back & compare until 0). Then start matching(same as lps) (see notebook)
// Time complexity: O(N+M)  ; Space complexity: O(M)

#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string p){
	vector<int> lps(p.size());
	lps[0]=0;
	int len=0;

	for(int i=1;i<p.size();i++){
		if(p[len]==p[i]){
			len++;
			lps[i]=len;
		}else{
			while(len>0){
				len=lps[len-1];
				if(p[len]==p[i]){
					len++;
					lps[i]=len;
					break;
				}
			}
			if(len==0){
				lps[i]=0;
			}
		}
	}

return lps;
}

int findPattern(string s, string p) {
    vector<int> lps=computeLPS(p);
    int i=0;
	int j=0;
	while(i<s.size()){
	    if(s[i]==p[j]){
		    i++;j++;
		    if(j==p.size()){
			    return i-j;
			}
		}else{
			while(j>0){
				j=lps[j-1];
				if(s[i]==p[j]){
					i++;j++;
					break;
				}
			}
			if(j==0){
				i++;
			}
		}
	}
return -1;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

	cout<<findPattern(s1,s2);
}