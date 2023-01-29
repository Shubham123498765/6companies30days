// Fraction to Recurring Decimal
// Link: https://leetcode.com/problems/fraction-to-recurring-decimal
// Time Complexity: O(N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string ans = "";
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) ans += '-';
        ll num = abs(numerator), den = abs(denominator); // converting to long long
        ll q = num / den, r = num % den;
        ans += to_string(q);
        
        if(r == 0) return ans;
        
        ans += '.';
        unordered_map<ll, int> mp;
        while(r != 0) {
            if(mp.find(r) != mp.end()){
                int pos = mp[r];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else {
                mp[r] = ans.length();
                r *= 10;
                q = r / den;
                r = r % den;
                ans += to_string(q);
            }
        }
        return ans;
    }
};