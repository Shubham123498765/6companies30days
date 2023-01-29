// Number of Boomerangs
// Link: https://leetcode.com/problems/number-of-boomerangs
// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {        
            unordered_map<long, int> group;
            for (int j = 0; j < points.size(); ++j) {
                if (j != i) {
                    int dy = points[i][1] - points[j][1];
                    int dx = points[i][0] - points[j][0];
                    group[dy * dy + dx * dx]++;
                }
            }
            
            for (auto& element : group) {
                // nP2 = n!/(n - 2)! = n * (n - 1)
                if (element.second > 1) ans += element.second * (element.second - 1);
            }
        }
        return ans;   
    }
};