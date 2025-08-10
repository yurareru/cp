// https://cses.fi/problemset/task/1676
// dsu, connectivity
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 100'005;
const int MAX_M = 200'005;

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int find(int x) { return (e[x] < 0 ? x : e[x] = find(e[x])); }
    int size(int x) { return -e[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    int c = n, maxs = 1;

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dsu.unite(u, v)) {
            maxs = max(maxs, dsu.size(u));
            c--;
        }
        cout << c << " " << maxs << endl;
    }
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
