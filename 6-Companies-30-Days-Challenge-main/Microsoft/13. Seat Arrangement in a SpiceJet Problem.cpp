// Seat Arrangement in a SpiceJet Problem
// Link: https://leetcode.com/problems/airplane-seat-assignment-probability/
// Time Complexity: O(1)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1.0;
        return 0.5;
    }
};