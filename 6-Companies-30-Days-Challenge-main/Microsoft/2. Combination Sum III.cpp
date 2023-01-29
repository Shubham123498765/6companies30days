// Combination Sum III
// Link: https://leetcode.com/problems/combination-sum-iii
// Time Complexity: O(9! / (9 - k)!)
// Space Complexity: O(9! / (9 - k)!) because of the recursion stack and the answer vector size

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findAnswer(vector<int> &arr, vector<vector<int>> &ans, int k, int n, int index, int start) {
        if(n == 0 && k == 0) {
            ans.push_back(arr);
            return;
        } else if (n <= 0 || k <= 0) return;

        for(int i = start; i <= 9; i++) {
            arr[index] = i;
            findAnswer(arr, ans, k - 1, n - i, index + 1, i + 1);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr(k);
        findAnswer(arr, ans, k, n, 0, 1);
        return ans;
    }
};