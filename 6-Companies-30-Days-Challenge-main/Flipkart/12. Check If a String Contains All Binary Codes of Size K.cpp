// Check If a String Contains All Binary Codes of Size K
// Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Time Complexity: O(N)
// Space Complexity: O(2^k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string str, int k) {
        int total = 1 << k;
        int oner = total - 1;
        int curr = 0;
        unordered_set<int> s;
        
        for(int i = 0; i < str.size(); i++) {
            curr = (((curr << 1) & oner) | (str[i] - '0'));
            if(i >= k - 1) s.insert(curr);
        }
    
        return (s.size() == total);
    }
};