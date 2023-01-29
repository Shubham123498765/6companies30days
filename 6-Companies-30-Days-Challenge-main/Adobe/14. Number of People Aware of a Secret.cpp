// Number of People Aware of a Secret
// Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/
// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int mod = 1000000000 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll ans = 0;
        vector<ll> v(n + 1, 0);
        v[0] = 1; //only 1 person knows the secret on day 1
        for(int i = 0; i < n; i++) {
            if(v[i] == 0) continue; //no one knows a secret
            for(int j = i + delay; j < n && (j - i) < forget; j++) {
                v[j] += v[i];
                v[j] = v[j] % mod;
            }
        }
        // taking last (forget-1) persons because the persons before that would have forgotten till nth day
        for(int i = n - 1; i >= n - forget; i--) {
            ans += v[i];
            ans = ans % mod;
        }
        return ans;
    }
};