#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define berak break
#define pii pair<int, int>
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 105;

vector<pii> adj[MAX_N];
int dist[MAX_N];
queue<int> bfs;

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int maxs = -INF;
    memset(dist, -1, sizeof dist);
    bfs.push(0);
    dist[0] = 0;
    while(!bfs.empty()) {
        auto u = bfs.front();
        bfs.pop();
        for (auto [v, w] : adj[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + w;
            maxs = max(maxs, dist[v]);
            bfs.push(v);
        }
    }
    cout << maxs << endl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}
