// Split a String Into the Max Number of Unique Substrings
// Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
// Time Complexity: O(N*2^N)
// Space Complexity: O(N*2^N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    int ans = 0;
    void dfs(string &s, int idx) {
        if(st.size() > ans) ans = st.size();
        if(idx >= s.length()) return;
        string str = "";
        for(int i = idx; i < s.length(); i++) {
            str += s[i];
            if(st.find(str)==st.end()) {
                st.insert(str);
                dfs(s,i + 1);
                st.erase(str);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }
};