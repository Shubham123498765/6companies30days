// Deletions to make an array divisible
// Link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible
// Time Complexity: O(NlogN) // N = Size of input array
// Space Complexity: O(N)

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = 0;
        for(auto element : numsDivide) {
            gcd = __gcd(gcd, element);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(gcd % nums[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};