// Evaluate Reverse Polish Notation
// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Will calculate the value based on the operator
    int calculate(int a, int b, string op) {
        if(op == "+") return a + b;
        if(op == "-") return a - b;
        if(op == "*") return a * b;
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int operand1, operand2;
        
        for(auto token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                if(st.size() > 1) {
                    int operand2 = st.top();
                    st.pop();
                    int operand1 = st.top();
                    st.pop();
                    st.push(calculate(operand1, operand2, token));
                } else {
                    // No need for checking in this question, as answer always eists.
                    return -1;
                }
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};