// Maximum Points in an Archery Competition
// Link: https://leetcode.com/problems/maximum-points-in-an-archery-competition
// Time Complexity: O(2^12)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int ans = INT_MIN;
    vector<int> tempp;

    void rec(int num, vector<int> &alice, int sum, int index, vector<int> &anss) {   
        if((index < 0 && num >= 0) || num == 0) {
            if(ans < max(ans,sum)) {
                for(int j = 0; j < 12; j++) tempp[j] = anss[j];
                tempp[0] += num; // If all arrows are not used
            }
            ans = max(ans,sum);
            return;
        } else if(index < 0) return;

        if(num >= alice[index]) {
            anss[index] = alice[index] + 1;
            rec((num - alice[index] - 1), alice, sum + index, index - 1, anss); // Take
            anss[index] = 0;
        }
        rec(num, alice, sum, index - 1, anss); // Leave
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows)  {
        tempp.resize(12, 0);
        vector<int> anss(12, 0);
        rec(numArrows, aliceArrows, 0, 11, anss);
        return tempp;
    }
};