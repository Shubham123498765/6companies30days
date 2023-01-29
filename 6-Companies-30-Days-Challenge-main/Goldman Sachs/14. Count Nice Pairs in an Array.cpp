// Count Nice Pairs in an Array
// Link: https://leetcode.com/problems/count-nice-pairs-in-an-array
// Time Complexity: O(N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 1000000000 + 7;

class Solution {
public:
    ll reverseDigits(int n) {
        ll ans = 0;
        while(n) {
            ans += n % 10;
            n /= 10;
            ans *= 10;
        }
        return ans / 10;
    } 

    int countNicePairs(vector<int>& nums) {
        ll cnt = 0;
        vector<int> temp = nums;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            temp[i] -= reverseDigits(temp[i]);
            freq[temp[i]]++;
        }
        for(auto ele : freq) {
            if(ele.second > 1) {
                ll n = ele.second - 1;
                cnt += (n * (n + 1)) / 2;
            }
        }
        return cnt % mod;
    }
};