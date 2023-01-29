// Substrings containing all three Characters
// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
// Time Complexity: O(N)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0, j = 0;
        vector<int> v(3, 0);
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'a']++;
            while(v[0] && v[1] && v[2]){
                cnt += s.size()-i;
                v[s[j]-'a']--;
                j++;
            }
        }
        return cnt;
    }
};