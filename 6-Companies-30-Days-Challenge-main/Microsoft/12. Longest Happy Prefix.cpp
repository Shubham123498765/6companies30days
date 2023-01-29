// Longest Happy Prefix
// Link: https://leetcode.com/problems/longest-happy-prefix
// Time Complexity: O(N) // N = Size of input string
// Space Complexity: O(N) // N = Size of input string

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        string ans = "";
        vector<int> pos(s.size(), 0);
        int i = 0, j = 1;
        while(j < s.size()) {
            if(s[i] == s[j]) {
                pos[j] = i + 1;
                i++;
                j++;
            }
            else if(i) i = pos[i - 1];
            else j++;
        }
        ans = s.substr(0, i);
        return ans;
    }
};