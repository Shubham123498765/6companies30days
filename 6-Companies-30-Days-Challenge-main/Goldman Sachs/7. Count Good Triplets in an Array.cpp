// Count Good Triplets in an Array
// Link: https://leetcode.com/problems/count-good-triplets-in-an-array
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n); 
        long long ans = 0;
        
        for(int i = 0; i < n; i++) pos[nums2[i]] = i;
        vector<int> left(n) , right(n);
        ordered_set s1, s2;
        
        // Getting all the lesser values then the current element
        for(int i = 0; i < n; i++){
            left[i] = s1.order_of_key(pos[nums1[i]]);
            s1.insert(pos[nums1[i]]);
        }

        // Trick: Using negative value to get all the greater values than the current element as pbds gives only the number of smaller values in O(logn)
        for(int i = n - 1; i >= 0; i--){
            right[i] = s2.order_of_key(-pos[nums1[i]]);
            s2.insert(-pos[nums1[i]]);
        }

        for(int i = 1; i < n - 1; i++) ans = ans + left[i] * 1LL * right[i];
        return ans;
    }
};