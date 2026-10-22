#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int low = 0, high = 2e9, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2; // mid = h
        int sum = 0;
        for (int i = 0; i < n; i++) sum += max(0LL, mid - a[i]);
        if (sum <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
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
