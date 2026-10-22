#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int l[n], r[n], rem[n];
        for (int i = 0; i < n; i++) cin >> l[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans += max(l[i], r[i]);
            rem[i] = min(l[i], r[i]);
        }
        sort(rem, rem + n, greater<int>());
        for (int i = 0; i < k - 1; i++) ans += rem[i];
        cout << ans << endl;
    }
}
