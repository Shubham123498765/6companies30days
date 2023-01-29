// Number of Matching Subsequences
// Link: https://leetcode.com/problems/number-of-matching-subsequences
// Time Complexity: O(N*M) where N is the length of string s and M is the number of words in words
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatches(string &curr, string &s) {
        int pos = 1;
        int i = s.find(curr[0]);
        if (i == -1) return false;
        while (pos < curr.length()) {
            i = s.find(curr[pos], i + 1);
            if (i == -1) return false;
            pos++;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (string str : words)
            if (hasMatches(str, s)) count++;
        
        return count;
    }
};

// This approach giving TLE (two pointers)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // create an array of pointers to keep track of the current position in each word
        vector<int> pointers(words.size(), 0); 
        int count = 0;
        for (char c : s) {
            for (int i = 0; i < words.size(); i++) {
                if (pointers[i] < words[i].size() && words[i][pointers[i]] == c) {
                    pointers[i]++;
                    if (pointers[i] == words[i].size()) count++;
                }
            }
        }
        return count;
    }
};
