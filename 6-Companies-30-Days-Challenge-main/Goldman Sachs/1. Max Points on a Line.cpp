// Max Points on a Line
// Link: https://leetcode.com/problems/max-points-on-a-line
// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxm = 0;
        int n = points.size();
        if(n <= 2) return n;
        for(int i = 0; i < n; i++) {
            double m;
            unordered_map<double, int> slope;
            for(int j = 0; j < n; j++) {
                double x1 = points[i][0], x2 = points[j][0];
                double y1 = points[i][1], y2 = points[j][1];
                if(i != j) {
                    if(x2 - x1) m = (y2 - y1) / (x2 - x1);
                    else m = INT_MAX;
                    slope[m]++;
                }
            }
            for(auto ele : slope) maxm = max(maxm, ele.second);
        }
        return maxm + 1;
    }
};