// Rotate Function
// Link: https://leetcode.com/problems/rotate-function
// Time Complexity: O(N)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int fx = 0; // f(x)
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            fx += i * nums[i];
        }
        int ans = fx;
        for(int i = n - 1; i > 0; i--) {
            fx += sum - (n * nums[i]);
            ans = max(ans, fx);
        }
        return ans;
    }
};