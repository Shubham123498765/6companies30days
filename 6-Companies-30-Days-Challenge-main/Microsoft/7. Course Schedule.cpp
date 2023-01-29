// Course Schedule
// Link: https://leetcode.com/problems/course-schedule
// Time Complexity: O(V+E) // V = Vertices, E = Edges
// Space Complexity: O(V+E) // V = Vertices, E = Edges

#include<bits/stdc++.h>
using namespace std;

// Basically we have to detect cycle in the graph
class Solution {
public:
    unordered_map<int, list<int>> adj_list;
    unordered_map<int, bool> visited, dfs_visited;
    
    bool checkCycleDFS(int curr) {
        visited[curr] = true;
        dfs_visited[curr] = true;
        for(auto i : adj_list[curr]) {
            if(!visited[i]) {
                bool cycleDetected = checkCycleDFS(i);
                if(cycleDetected) return true;
            } else if (dfs_visited[i]) return true;
        }
        dfs_visited[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre : prerequisites) {
            adj_list[pre[0]].push_back(pre[1]); // Taking graph input
        }

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                bool cycleFound = checkCycleDFS(i);
                if(cycleFound) return false;
            }
        }
        return true;
    }
};