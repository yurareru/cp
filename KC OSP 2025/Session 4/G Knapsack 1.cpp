#include <bits/stdc++.h>

using namespace std;

long long dp[2][100005] = {0};
void solve() {
    int N, W;
    cin >> N >> W;
    int weight[N + 5], value[N + 5];

    for (int i = 1; i <= N; i++) {
        cin >> weight[i] >> value[i];
    }

    // state = barang ke-i dan weight yang sudah kita gunakan

    // transition =
    // - skip => i+1, weight dan value tetap
    // - ambil => i+1, weight dan value bertambah
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i & 1][w] = dp[(i - 1) & 1][w]; // skip
            if (w + weight[i] <= W) {
                dp[i & 1][w] =
                    max(dp[i & 1][w],
                        dp[(i - 1) & 1][w + weight[i]] + value[i] // ambil
                    );
            }
        }
    }
    long long ans = 0;
    for (int w = 0; w <= W; w++) {
        ans = max(ans, dp[N & 1][w]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
