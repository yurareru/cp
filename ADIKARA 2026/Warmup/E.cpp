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

    vector<pii> v;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.pb({start, end});
    }

    sort(v.begin(), v.end(), [](pii a, pii b) { return a.second < b.second; });

    int prev_end = -2147483648, count = 0;

    for (auto [start, end] : v) {
        if (start >= prev_end + 15) {
            count++;
            prev_end = end;
        }
    }
    cout << count << nl;
}
