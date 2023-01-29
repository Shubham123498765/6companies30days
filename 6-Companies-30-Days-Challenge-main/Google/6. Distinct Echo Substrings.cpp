// Distinct Echo Substrings
// Link: https://leetcode.com/problems/distinct-echo-substrings/

#include<bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<string> s;
        for(int start = 0; start < n - 1; start++) {
            for(int i = start + 1; i < n; i++) {
                string temp = "";
                if(text[i] == text[start]) {
                    int m = i - start, flag = 1;
                    int k = start + m;
                    for(int j = start; j < start + m; j++) {
                        if(text[j] == text[k]) {
                            temp += text[j];
                            k++;
                        } else {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) s.insert(temp);
                }
            }
        }
        return s.size();
    }
};

// Optimized
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int distinctEchoSubstrings(string s) {
        unordered_map<string,int> mp;
        for(int i = 0; i < s.size(); i++){
            string re;
            vector<int> nums = {0}; int l = 0;
            for(int j = i + 1; j < s.size(); j++){
                re += string(1,s[j]);
                while(l > 0 && s[i+l] != s[j])  l = nums[l-1];
                if(s[l + i] == s[j]) {nums.push_back(l+1); l++;}
                else nums.push_back(0);
                int p = j - i + 1 - nums[nums.size() - 1];
                if((j - i) % 2 != 0 && (p && (j - i + 1) % p == 0 && ((j - i + 1) / p) % 2 == 0)) mp[re]++; 
            }
        }
        return mp.size();
    }
};