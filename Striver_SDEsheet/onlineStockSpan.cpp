// Approach: Keep stack of type pair containing (value,index) pairs. Find previous greater element for each element(maintain stack in ascending order) and find difference of size & element greater. Also push element in stack top
// Time complexity: O(N) ; Space complexity: O(2N)

#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int,int>> st;
    int size;

public:
    StockSpanner() {
        size=0;
    }
    
    int next(int price){
        size++;
        //previous greater element
        if(st.empty() || st.top().first>price){
            st.push({price,size});
            return 1;
        }else{
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            
            if(st.empty()){
                st.push({price,size});
                return size;
            }else{
                int ans=(size-st.top().second);
                st.push({price,size});
                return ans;
            }
        }
    }
};