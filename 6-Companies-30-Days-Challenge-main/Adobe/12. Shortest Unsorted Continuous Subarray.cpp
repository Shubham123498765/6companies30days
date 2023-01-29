// Shortest Unsorted Continuous Subarray
// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Time Complexity: O(N)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minm = INT_MAX, maxm = INT_MIN;
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                flag = true;
            if (flag)
                minm = min(minm, nums[i]);
        }
        flag = false;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                flag = true;
            if (flag)
                maxm = max(maxm, nums[i]);
        }
        int l, r;
        for (l = 0; l < nums.size(); l++) {
            if (minm < nums[l])
                break;
        }
        for (r = nums.size() - 1; r >= 0; r--) {
            if (maxm > nums[r])
                break;
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
};