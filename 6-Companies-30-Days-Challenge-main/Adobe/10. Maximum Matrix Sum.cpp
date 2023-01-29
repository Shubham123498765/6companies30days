// Maximum Matrix Sum
// Link: https://leetcode.com/problems/maximum-matrix-sum/
// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll n = matrix.size(), cnt = 0, sum = 0;
        int minm = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);
                minm = min(minm, abs(matrix[i][j]));
                if(matrix[i][j] < 0) cnt++;
            }
        }
        if(cnt % 2) return sum - 2 * minm; // Because we are also considering it while adding in sum. Thatswhy we have to subtract it two times.
        return sum;
    }
};