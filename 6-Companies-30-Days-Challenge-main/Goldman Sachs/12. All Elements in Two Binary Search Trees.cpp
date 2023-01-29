// All Elements in Two Binary Search Trees
// Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees
// Time Complexity: O(NlogN)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traverseTree(TreeNode* root, vector<int> &tree) {
        if(root) {
            tree.push_back(root->val);
            traverseTree(root->left, tree);
            traverseTree(root->right, tree);
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2, tree;
        traverseTree(root1, tree1);
        traverseTree(root2, tree2);
        for(auto ele : tree1) tree.push_back(ele);
        for(auto ele : tree2) tree.push_back(ele);
        sort(tree.begin(), tree.end());
        return tree;
    }
};