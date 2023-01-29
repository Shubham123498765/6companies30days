// Largest Divisible Subset
// Link: https://leetcode.com/problems/largest-divisible-subset
// Explaination without code: https://www.youtube.com/watch?v=Wv6DlL0Sawg
// Time Complexity: O(N^2) // N = Size of input array
// Space Complexity: O(N) // N = Size of input array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), max_index = 1, num = -1;
        vector<int> ans;
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(!(nums[i] % nums[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    if(max_index < dp[i]) max_index = dp[i];
                }
            } 
        }
        for(int i = n - 1; i >= 0; i--) {
            if(max_index == dp[i] && (num == -1 || !(num % nums[i]))) {
                ans.push_back(nums[i]);
                max_index--;
                num = nums[i];
            }
        }
        return ans;
    }
};  