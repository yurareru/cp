#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        f[i] = t - f[i];
    }

    sort(f.begin(), f.end());
    int l = 0, r = n - 1, ans = 0;
    while (l < r) {
        while (l < r && f[l] + f[r] < 0) l++;
        if (l >= r) break;
        ans++;
        l++, r--;
    }
    cout << ans << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
