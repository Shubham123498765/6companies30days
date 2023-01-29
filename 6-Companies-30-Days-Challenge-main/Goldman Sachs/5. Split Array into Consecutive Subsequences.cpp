// Split Array into Consecutive Subsequences
// Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences
// Time Complexity: O(N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq, need;
        for(int x: nums) freq[x]++;

        for(int n: nums){
            if(freq[n] == 0) continue;
            if(need[n] > 0){ // checking for existing subs
                need[n]--;
                freq[n]--;
                need[n + 1]++;
            } else if (freq[n] > 0 && freq[n + 1] > 0 && freq[n + 2] > 0){ // new subs
                freq[n]--;
                freq[n + 1]--;
                freq[n + 2]--;
                need[n + 3]++;
            } else return false;
        }
        
        return true;
    }
};