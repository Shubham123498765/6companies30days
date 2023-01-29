// Invalid Transactions
// Link: https://leetcode.com/problems/invalid-transactions/
// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name, city, ans;
        vector<int> time, amount;
        for(auto transaction : transactions) {
            string temp1 = "", temp2 = "", temp3 = "", temp4 = "";
            int word = 0;
            for(int i = 0; i < transaction.length(); i++) {
                if(transaction[i] == ',') {
                    word++;
                    continue;
                }
                if(word == 0) temp1 += transaction[i]; 
                if(word == 1) temp2 += transaction[i]; 
                if(word == 2) temp3 += transaction[i]; 
                if(word == 3) temp4 += transaction[i]; 
            }
            name.push_back(temp1);
            city.push_back(temp4);
            time.push_back(stoi(temp2));
            amount.push_back(stoi(temp3));
        }
        for(int i = 0; i < n; i++) {
            if(amount[i] > 1000) ans.push_back(transactions[i]);
            else {
                for(int j = 0; j < n; j++) {
                    if(j != i) {
                        if(name[i] == name[j] && abs(time[i] - time[j]) <= 60 && city[i] != city[j]) {
                            ans.push_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};