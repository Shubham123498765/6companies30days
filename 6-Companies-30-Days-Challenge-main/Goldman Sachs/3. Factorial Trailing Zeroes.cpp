// Factorial Trailing Zeroes
// Link: https://leetcode.com/problems/factorial-trailing-zeroes
// Time Complexity: O(logN)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        return (n) ? n / 5 + trailingZeroes(n / 5) : 0;
    }
};