// Approach: Start iterating from end. Stay on the denominations,keep decrementing amount by denomination and increment count, until denomination is greater than the amount left
// Time complexity:O(V) ; Space complexity:O(1)

#include <bits/stdc++.h> 
using namespace std;

int findMinimumCoins(int amount) {
    int coins[]={1,2,5,10,20,50,100,500,1000};
    
    int count=0;
    int i=8;
    while(amount!=0){
        while(amount>=coins[i]){
            amount-=coins[i];
            count++;
        }
        i--;
    }
    
return count;
}
