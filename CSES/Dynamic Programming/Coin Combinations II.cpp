// https://cses.fi/problemset/task/1636
// combinatorics
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];

    int dp[x + 5] = {0}; // number of ways to achieve sum
    dp[0] = 1;           // 1 way to achieve sum = 0

    for (int c : coins) {
        for (int i = c; i <= x; i++) {
            dp[i] += dp[i - c];
            dp[i] %= MOD;
        }
    }
    cout << dp[x] << endl;
}
