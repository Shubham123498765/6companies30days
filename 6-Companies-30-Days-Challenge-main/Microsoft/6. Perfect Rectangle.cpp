// Largest Perfect Rectangle
// Link: https://leetcode.com/problems/perfect-rectangle/
// Time Complexity: O(N) // N = Number of rectangles
// Space Complexity: O(N) // N = Number of rectangles

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        /* NOTE: We cannot use unordered_map with pairs because unordered Map 
        does not contain a hash function for a pair like it has for int, 
        string, etc, So if we want to hash a pair then we have to explicitly 
        provide it with a hash function that can hash a pair.*/
        map<pair<int, int>, int> m;
        
        // Idea is that count of all the interior points = 0
        // |Count of all the exterior points| = 4
        for(auto rect : rectangles) {
            m[{rect[0], rect[1]}]++;
            m[{rect[2], rect[3]}]++;
            m[{rect[0], rect[3]}]--;
            m[{rect[2], rect[1]}]--;
        }

        int rect_count = 0;
        for(auto element : m) {
            if(abs(element.second) != 0) {
                if(abs(element.second) == 1) rect_count++;
                else return false;
            }
        }
        return rect_count == 4;
    }
};