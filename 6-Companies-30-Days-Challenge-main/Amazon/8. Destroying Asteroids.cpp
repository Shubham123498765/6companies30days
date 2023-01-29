// Destroying Asteroids
// Link: https://leetcode.com/problems/destroying-asteroids/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long int totalMass = mass;
        for(auto asteroid : asteroids) {
            if(asteroid > totalMass) return false;
            totalMass += asteroid;
        }
        return true;
    }
};