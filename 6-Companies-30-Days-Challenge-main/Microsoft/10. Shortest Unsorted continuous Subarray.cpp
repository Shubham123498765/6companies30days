// Shortest Unsorted continuous Subarray
// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Time Complexity: O(NlogN) // N = Size of input array
// Space Complexity: O(N) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> rev = nums;
        int n = nums.size(), ans = 0, left = 0, right = n - 1, flag1 = 0, flag2 = 0;
        sort(rev.begin(), rev.end());

        for(int i = 0; i < n; i++) {
            if (flag1 && flag2) {
                ans = right - left + 1;
                break;
            }
            if(nums[i] != rev[i] && !flag1)  {
                left = i;
                flag1 = 1;
            }
            if(nums[n - i - 1] != rev[n - i - 1] && !flag2)  {
                right = n - i - 1;
                flag2 = 1;
            }
        }
        return ans;
    }
};