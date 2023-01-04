// Approach: See all possible sum combinations. Store them in a set. Then push them first k of them in the resultant vector
// Time complexity: O(N^2) ; Space complexity: O(N^2)


// Approach: Sort both arrays. Then push biggest sum combination(last of both) in specially designed priority queue. For k biggest sum combinations each time store top of pq in ans and inplace of it add sum(i-1,j) & sum(i,j-1) to it. Also use a set to store indices used till now
// Time complexity: O(NlogN + k*2logk) ; Space complexity: O(2k)

#include<bits/stdc++.h>
using namespace std;

class comb{
    public:
        int val;
        int idx;
        int jdx;
};

struct cmp{
    bool operator()(comb c1,comb c2){  //-? see why

        return c1.val<c2.val;//do opposite in queue, we want decreasing on based of value so arrange in increasing(inverts decreasing to increasing)
    
    }
};

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

    priority_queue<comb, vector<comb>, cmp> pq;//Max priority queue for sums
    set<pair<int,int>> s;//set to store indices used for each sum
    vector<int> ans;

    pq.push({a[n-1]+b[n-1],n-1,n-1});//push highest sum directly to ans{unless k=0 & we want no combination sum}
    s.insert({n-1,n-1});//insert indices used for this sum
    
    for(int i=0;i<k;i++){
        comb curr=pq.top();
        pq.pop();

        int val=curr.val;
        int idx=curr.idx;
        int jdx=curr.jdx;

        //push combination sum in ans
        ans.push_back(val);

        //push i,j-1 and i-1,j if possible in pq and set
        if(idx>0 && s.count({idx-1,jdx})==0){
            pq.push({a[idx-1]+b[jdx],idx-1,jdx});
            s.insert({idx-1,jdx});
        }

        if(jdx>0 && s.count({idx,jdx-1})==0){
            pq.push({a[idx]+b[jdx-1],idx,jdx-1});
            s.insert({idx,jdx-1});
        }
    }
return ans;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,k;
    cin>>n>>k;
    int ele;
    vector<int> a;
    vector<int> b;

    for(int i=0;i<n;i++){
        cin>>ele;
        a.push_back(ele);
    }

    for(int i=0;i<n;i++){
        cin>>ele;
        b.push_back(ele);
    }

    vector<int> ans;
    ans=kMaxSumCombination(a,b,n,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
return 0;
}