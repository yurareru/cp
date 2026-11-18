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
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;
    ll ans = 0, temp = 0;
    for (int l = 0, r = 0; r < n; l = r, r++) {
        if (a[l] <= a[r]) {
            temp++;
            ans = max(ans, temp);
        } else {
            ans = max(ans, temp);
            temp = 1;
        }
    }
    cout << ans << nl;
}
