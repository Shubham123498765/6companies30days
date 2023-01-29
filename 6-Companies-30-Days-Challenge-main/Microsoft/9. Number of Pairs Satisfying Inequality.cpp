// Number of Pairs Satisfying Inequality
// Link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality
// Time Complexity: O(NlogN)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Solution {
public:
    ll findCount(int left, int right, vector<int> &nums, int diff) {
        if(left == right) return 0;
        int mid = (left + right) / 2;
        // Calculating values from left and right part after dividing
        ll result = findCount(left, mid, nums, diff) + findCount(mid + 1, right, nums, diff);

        // Calculating value while merging both left and right part
        int l1 = left, r1 = mid, l2 = mid + 1, r2 = right;
        for(int j = l2; j <= r2; j++) {
            int index = upper_bound(nums.begin() + l1, nums.begin() + r1 + 1, nums[j] + diff) - nums.begin() - 1;
            if(index <= r1) result += index - l1 + 1;
        }
        // Sorting left and right part to make further calculation easy
        // Because order of values in left and right parts are independent to each other 
        sort(nums.begin() + l1, nums.begin() + r2 + 1);
        
        return result;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n);
        for(int i = 0; i < n; i++) nums[i] = nums1[i] - nums2[i];
        
        // now we have to solve nums[i] <= nums[j] + diff and i < j
        return findCount(0, n - 1, nums, diff);
    }
};