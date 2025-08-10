// https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;
const int INF = 1e9;

int dp[MAXN];

int main() {
    int n;
    cin >> n;

    fill(dp, dp + MAXN, INF);
    for (int i = 1; i <= 9; i++) dp[i] = 1;

    for (int i = 10; i <= n; i++) {
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            if (i - digit >= 0 && digit > 0) {
                dp[i] = min(dp[i], 1 + dp[i - digit]);
            }
        }
    }

    cout << dp[n] << endl;
}
