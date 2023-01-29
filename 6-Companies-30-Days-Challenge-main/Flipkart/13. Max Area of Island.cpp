// Max Area of Island
// Link: https://leetcode.com/problems/max-area-of-island/
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int sr , int sc , int &area, vector<vector<int>>& grid) {
        if(!(sr >= 0 && sr < grid.size() && sc >= 0 && sc < grid[0].size() && grid[sr][sc] == 1 )) return; // out of bound condition
        area++; // increase area by 1
        grid[sr][sc] = 0; // make current element 0 to make it visited
        dfs(sr - 1 , sc , area , grid); // move upward
        dfs(sr , sc + 1 , area, grid);  // move right
        dfs(sr + 1, sc , area, grid);  // move down
        dfs(sr, sc - 1, area , grid);  // move left
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int area = 0;

        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){ 
                    dfs(i, j, area, grid);
                    max_area = max(max_area, area);
                    area = 0;
                }
            }
        }
        return max_area;
    }
};