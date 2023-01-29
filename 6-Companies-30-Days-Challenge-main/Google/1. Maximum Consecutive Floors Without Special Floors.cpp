// Maximum Consecutive Floors Without Special Floors
// Link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int& bottom, int& top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans = max(0, special[0] - bottom);
        for(int i = 1; i < special.size(); i++){
            ans = max(ans,special[i] - special[i - 1] - 1);
        }
        ans = max(ans, top - special[special.size() - 1]);
        return ans;
    }
};