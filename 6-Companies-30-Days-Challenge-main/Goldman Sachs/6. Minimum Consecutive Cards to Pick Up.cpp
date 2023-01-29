// Minimum Consecutive Cards to Pick Up
// Link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up
// Time Complexity: O(N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> m;
        int n = cards.size(), minm = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(m.find(cards[i]) != m.end()) minm = min(minm, i - m[cards[i]] + 1);
            m[cards[i]] = i;
        }
        return (minm == INT_MAX) ? -1 : minm;
    }
};