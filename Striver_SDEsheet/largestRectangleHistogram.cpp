// Naive approach: Find area of each height possible. Traverse in both directions and find max possible width with that height. Calculate area
// Time complexity: O(N^2) ; Space complexity: O(1)


// Better Approach: Find area of each height possible.Prepare a previous smaller element & next smaller element vector for each height which stores at which index the last/next smaller element will occur(reset for boundary as we want the bigger element after/before smaller element for area +1/-1) Then calculate area for each height by (nse[i]-pse[i]+1)*h[i]
// Time complexity: O(2N+N+2N+N) ; Space complexity: O(3N)

#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    vector<int> pse;
    vector<int> nse;
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i]=0;
        }else{
            pse[i]=st.top()+1; //pse is at st.top() but boundary will be 1 higher index than it(think in diagram)
        }
        st.push(i);
    }

    while(!st.empty())st.pop();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i]=n-1;
        }else{
            nse[i]=st.top()-1; //nse is at st.top() but boundary will be set at 1 lesser index(thing in diagram)
        }
        st.push(i);
    }
    int areaMax=INT_MIN;
    int area;
    for(int i=0;i<n;i++){
        area=heights[i]*(nse[i]-pse[i]+1);
        areaMax=max(areaMax,area);
    }

return areaMax;
}

// Optimal approach: Calculate pse,nse of all elements in a single iteration. Keep pushing elements in stack so it follows increasing order. when smaller element comes it is nse of all elements it is smaller than. Pop those elements & new top will be pse. Calculate area for the popped element
// Time complexity: O(N+N) {push and pop N elements} ; Space complexity: O(N)

int largestRectangle(vector<int>& heights){
    stack<int> st;
    int n=heights.size();
    int maxArea=0;
    int area=0;
    int nse,pse,h;

    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n ||heights[i]<heights[st.top()])){
            nse=i-1; //nse is at i but boundary will be set at 1 lesser index(thing in diagram)
            h=heights[st.top()];
            st.pop();
            if(st.empty()){
                pse=0;
            }else{
                pse=st.top()+1; //pse is at st.top() but boundary will be 1 higher index than it(think in diagram)
            }
            maxArea=max(maxArea,(nse-pse+1)*h);
        }
        st.push(i);
    }
return maxArea;
}