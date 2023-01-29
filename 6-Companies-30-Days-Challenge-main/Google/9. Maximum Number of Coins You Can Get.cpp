// Maximum Number of Coins You Can Get
// Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int ans = 0;
        int n = piles.size();
        for(int i = 0; i < n; i += 2){
            ans += piles[i + 1];
            n--;
        }
        return ans;
    }
};