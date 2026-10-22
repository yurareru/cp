#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> h(n);

    for (auto& i : h) {
        cin >> i;
    }

    vector<int> dp(n, 0);

    dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1] << endl;
}
