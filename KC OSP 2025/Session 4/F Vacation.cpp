#include <bits/stdc++.h>

using namespace std;

const int MAXN =  100'005;

// happines if at ith day choosing activity j
int dp[MAXN][3];

int main() {
    int n; cin >> n;
    int h[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> h[i][j];
        }
    }
    
    for (int j = 0; j < 3; j++) {
        dp[0][j] = h[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            // kalo ambil A berarti cuman boleh B or C
            if (j == 0) {
                dp[i][j] = max(dp[i-1][1], dp[i-1][2]) + h[i][j];
            } else if (j == 1) {
                dp[i][j] = max(dp[i-1][0], dp[i-1][2]) + h[i][j];
            } else {
                dp[i][j] = max(dp[i-1][0], dp[i-1][1]) + h[i][j];
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 3; j++) {
        ans = max(ans, dp[n-1][j]);
    }
    cout << ans << endl;
}