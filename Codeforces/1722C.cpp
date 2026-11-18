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
    cin >> tc;
    while (tc--) solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    map<string, vi> m;
    vi p(3, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            m[s].pb(i);
        }
    }
    for (auto [k, v] : m) {
        for (int i : v) {
            if (v.size() == 1) p[i] += 3;
            if (v.size() == 2) p[i] += 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << p[i] << " ";
    }
    cout << nl;
}
