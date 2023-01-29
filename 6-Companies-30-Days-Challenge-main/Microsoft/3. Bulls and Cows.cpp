// Bulls and Cows
// Link: https://leetcode.com/problems/bulls-and-cows
// Time Complexity: O(N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int size = secret.length();
        int bulls = 0, cows = 0;
        for(int i = 0; i < size; i++) {
            if(m.find(secret[i]) != m.end()) m[secret[i]]++;
            else m[secret[i]] = 1;
        }

        for(int i = 0; i < size; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
                m[secret[i]]--;
            }
        }

        for(int i = 0; i < size; i++) {
            if(m.find(guess[i]) != m.end() && guess[i] != secret[i]) {
                if(m[guess[i]] > 0) {
                    cows++;
                    m[guess[i]]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};