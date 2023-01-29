// Valid Square
// Link: https://leetcode.com/problems/valid-square
// Time Complexity: O(1)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDistance(vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s;
        s.insert(findDistance(p1, p2));
        s.insert(findDistance(p1, p3));
        s.insert(findDistance(p1, p4));
        s.insert(findDistance(p2, p3)); 
        s.insert(findDistance(p2, p4)); 
        s.insert(findDistance(p3, p4));      
        return (!s.count(0) && s.size() == 2);
    }
};