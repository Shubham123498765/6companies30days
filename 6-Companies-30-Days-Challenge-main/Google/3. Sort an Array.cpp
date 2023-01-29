// Sort an array
// Link: https://leetcode.com/problems/sort-an-array/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
     void heapify(vector<int>&nums,int n,int i){
       int l=2 * i + 1;
       int r=2 * i + 2;
       int lar = i;

       if(l < n && nums[l] > nums[lar])
          lar = l;
        if(r < n && nums[r] > nums[lar])
         lar = r;

         if(lar != i){
             swap(nums[lar], nums[i]);
             heapify(nums, n, lar);
         }
    }
     
    void buildheap(vector<int> &nums, int n){
        for(int i = (n - 2) / 2; i >= 0; i--){
            heapify(nums, n, i);
        }
    }

    void heapsort(vector<int> &nums, int n){
        buildheap(nums, n);

        for(int i = n - 1; i >= 0; i--){
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums, nums.size());
        return nums;
    }
};