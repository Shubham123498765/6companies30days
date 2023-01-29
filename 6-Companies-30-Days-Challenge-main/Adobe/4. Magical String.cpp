// Magical String
// Link: https://leetcode.com/problems/magical-string/
// Time Complexity: O(N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string str = "";
        str += "122";
        int index = 2,countOfOne = 1;
        while(index < n && str.size() < n) {
            if(str[index] == '1') {
                countOfOne++;
                str += (str[str.size() - 1] == '2') ? '1' : '2';
            }
            else str += (str[str.size() - 1] == '2') ? "11" : "22";
            index++;
        }
        while(index < n) {
            if(str[index] == '1')
            countOfOne++;
            index++;
        }
        return countOfOne;
    }
};