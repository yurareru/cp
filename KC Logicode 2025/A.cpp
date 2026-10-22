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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    ll max_count = 0;
    for (int i = 0; i < n; i++) {
        ll sum = 0, count = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (0 <= sum && sum <= m) {
                count++;
                max_count = max(count, max_count);
            } else
                berak;
        }
    }
    // for (int l = 0, r = 0; r < n; r++) {
    //     sum += a[r];
    //     while (l <= r && (sum > m || sum < 0)) {
    //         sum -= a[l++];
    //         count--;
    //     }
    //     if (0 <= sum && sum <= m) {
    //         count++;
    //     }
    // }
    cout << max_count << endl;
}
