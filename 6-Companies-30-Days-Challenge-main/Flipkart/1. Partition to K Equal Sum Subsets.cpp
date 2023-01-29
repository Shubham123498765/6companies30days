// Partition to K Equal Sum Subsets
// Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Time Complexity: O(N^k)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool backtrack(vector<int>& nums,vector<int>visited, int target, int curr_sum, int i, int k) {
        if (k == 1) return true;
        
        if (curr_sum == target) return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
            visited[j] = false;
            if(curr_sum == 0) break;
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) return false;
        vector<int>visited(nums.size(), false);
        return backtrack(nums, visited, sum / k, 0, 0, k);
    }
};