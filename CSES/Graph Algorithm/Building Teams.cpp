// https://cses.fi/problemset/task/1668
// bipartite, coloring
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define nl '\n'
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;

vector<int> adj[MAX_N];
int color[MAX_N];

bool dfs(int u, int c) {
    if (color[u] != -1) return color[u] == c;
    color[u] = c;
    for (auto v : adj[u]) {
        if (!dfs(v, 1 - c)) return false;
    }
    return true;
}

void solve() {
    memset(color, -1, sizeof color);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                cout << "IMPOSSIBLE" << nl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << color[i] + 1 << " ";
    }
    cout << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
