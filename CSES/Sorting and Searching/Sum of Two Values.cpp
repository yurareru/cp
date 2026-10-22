// https://cses.fi/problemset/task/1640/
// two pointer
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[i] = {v, i};
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    pii ans;
    bool impossible = 1;
    while (l < r) {
        if (a[l].first + a[r].first == x) {
            ans = {a[l].second + 1, a[r].second + 1};
            impossible = 0;
            break;
        } else if (a[l].first + a[r].first < x)
            l++;
        else
            r--;
    }
    if (impossible) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans.first << ' ' << ans.second << endl;
}
