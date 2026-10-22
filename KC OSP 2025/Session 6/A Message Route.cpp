#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_E = 2e5 + 5;

int V, E; // n, m
vector<int> adj[MAX_V];
queue<int> bfs;
int dist[MAX_V];
int prv[MAX_V];

void solve() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 0, finish = V - 1;

    memset(dist, -1, sizeof dist);
    dist[start] = 0;
    bfs.push(start);

    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();
        for (int v : adj[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            prv[v] = u;
            bfs.push(v);
        }
    }

    if (dist[finish] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << dist[finish] + 1 << endl;

    vector<int> path;
    for (int u = finish; u != start; u = prv[u]) path.push_back(u);
    path.push_back(start);

    reverse(path.begin(), path.end());

    for (auto p : path) cout << p + 1 << " ";
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
