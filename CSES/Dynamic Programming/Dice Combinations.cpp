// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;

int dp[MAXN] = {0};

int main() {
    int n;
    cin >> n;
    int dice[6] = {1, 2, 3, 4, 5, 6};
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int d : dice) {
            if (i - d >= 0) {
                dp[i] += dp[i - d];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
}
