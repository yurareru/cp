#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[100005][16];

void add(int& a, int b) { a = (a + b) % MOD; }

int main() {
    int t;
    cin >> t;
    dp[0][15] = 1;
    int i = 1;
    while (t--) {
        int n;
        cin >> n;
        for (; i <= n; i++) {
            if (dp[i][15] != 0) continue;
            // 0000
            add(dp[i][0], dp[i - 1][15]);
            // 1000 0100 0010 0001
            add(dp[i][1], dp[i - 1][14]);
            add(dp[i][2], dp[i - 1][13]);
            add(dp[i][3], dp[i - 1][12]);
            add(dp[i][4], dp[i - 1][11]);
            // 1100
            add(dp[i][5], dp[i - 1][15]);
            add(dp[i][5], 2 * dp[i - 1][10]);
            // 1010 1001
            add(dp[i][6], dp[i - 1][9]);
            add(dp[i][7], dp[i - 1][8]);
            // 0110
            add(dp[i][8], dp[i - 1][15]);
            add(dp[i][8], 2 * dp[i - 1][7]);
            // 0101
            add(dp[i][9], dp[i - 1][6]);
            // 0011
            add(dp[i][10], dp[i - 1][15]);
            add(dp[i][10], 2 * dp[i - 1][5]);
            // 1110
            add(dp[i][11], dp[i - 1][12]);
            add(dp[i][11], dp[i - 1][14]);
            add(dp[i][11], 3 * dp[i - 1][4]);
            // 1101
            add(dp[i][12], dp[i - 1][11]);
            add(dp[i][12], 2 * dp[i - 1][3]);
            // 1011
            add(dp[i][13], dp[i - 1][14]);
            add(dp[i][13], 2 * dp[i - 1][2]);
            // 0111
            add(dp[i][14], dp[i - 1][13]);
            add(dp[i][14], dp[i - 1][11]);
            add(dp[i][14], 3 * dp[i - 1][1]);
            // 1111
            add(dp[i][15], 5 * dp[i - 1][0]);
            add(dp[i][15], dp[i - 1][15]);
            add(dp[i][15], dp[i - 1][8]);
            add(dp[i][15], 2 * dp[i - 1][5]);
            add(dp[i][15], 2 * dp[i - 1][10]);
        }
        cout << dp[n][15] << endl;
    }
}
