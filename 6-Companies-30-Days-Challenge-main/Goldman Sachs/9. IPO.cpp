// IPO
// Link: https://leetcode.com/problems/ipo
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), pos = 0;
        vector<pair<int, int>> projects;
        for(int i = 0; i < n; i++) projects.push_back({capital[i], profits[i]});
        sort(projects.begin(), projects.end());
        priority_queue<int> q;
        for(int i = 0; i < k; i++) {
            while(pos < n && projects[pos].first <= w) q.push(projects[pos++].second);
            if(q.empty()) break;
            w += q.top(); // Update the capital
            q.pop(); // Remove the currect maxm profit
        }
        return w;
    }
};