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
    queue<pii> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q.push({x, i});
    }
    int last = 0;
    while (!q.empty()) {
        auto [x, i] = q.front();
        q.pop();
        last = i;
        if (x > m) {
            q.push({x - m, i});
        }
    }
    cout << last;
}
