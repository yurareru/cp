#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a[i] = val;
        sum += val;
    }

    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
          int cur = sum - a[i];  // remove a[i]

        // x <= cur - a[j] <= y
        // cur - x >= a[j] >= cur - y
        // cur - y <= a[j] <= cur - x
        
        // find valid j using binary search in a[i+1..n-1]
        // find first j >= cur - y
        auto l = lower_bound(a.begin() + i + 1, a.end(), cur - y);

        // find first j > cur - x
        auto r = upper_bound(a.begin() + i + 1, a.end(), cur - x);

        count += r - l;
    }
    cout << count << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}