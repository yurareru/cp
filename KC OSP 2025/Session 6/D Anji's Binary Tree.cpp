#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define pb push_back

const int MAX_N = 3e5 + 5;

vector<pii> adj[MAX_N];
int dist[MAX_N];
bool leaf[MAX_N];

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        fill(dist, dist + MAX_N, 1e9);
        memset(leaf, 0, sizeof leaf);
        ll n;
        string s;
        cin >> n >> s;
        s = ' ' + s;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            int l, r;
            cin >> l >> r;
            l > 0 && s[i] == 'L' ? adj[i].pb({ l, 0 }) : adj[i].pb({ l, 1 });
            r > 0 && s[i] == 'R' ? adj[i].pb({ r, 0 }) : adj[i].pb({ r, 1 });
            if (l == 0 && r == 0) leaf[i] = true;
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << i << ": ";
        //     for (auto a : adj[i]) {
        //         cout << a.first << " ";
        //     }
        //     cout << '\n';
        // }

        int minimum = 1e9;
        queue<int> bfs;
        bfs.push(1);
        dist[1] = 0;
        while (!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            for (auto [v, w] : adj[u]) {
                if (dist[v] != 1e9) continue;
                dist[v] = dist[u] + w;
                bfs.push(v);
                if (leaf[v]) minimum = min(minimum, dist[v]);
            }
        }
        cout << minimum << endl;
    }
}
