#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int hewan[2005], sum[2005];
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; i++) {
        cin >> hewan[i];
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            sum[i] += hewan[i];
        }
    }
    int ans = 0;
    sort(sum + 1, sum + n + 1, greater<int>());
    for (int i = 1; i <= k; i++) {
        ans += sum[i];
    }
    cout << ans << endl;
}
