// https://cses.fi/problemset/task/1641
// two pointers
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define berak break
#define Bismillah ios_base::sync_with_stdio(false);
#define AC cin.tie(nullptr);

constexpr char nl = '\n';
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr int MAX_N = 1005;

void solve();

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int target = x - a[i].first;
        int l = i + 1, r = n - 1;
        while (l < r) {
            ll sum = a[l].first + a[r].first;
            if (sum == target) {
                vi ans = {a[i].second, a[l].second, a[r].second};
                sort(ans.begin(), ans.end());
                for (auto j : ans) cout << j << " ";
                return;
            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
