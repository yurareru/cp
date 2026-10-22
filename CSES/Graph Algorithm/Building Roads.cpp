// https://cses.fi/problemset/task/1666
// dsu, connectivity
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define nl '\n'
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int find(int x) { return (e[x] < 0 ? x : e[x] = find(e[x])); }
    int size(int x) { return -e[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int n, m;

void solve() {
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dsu.unite(u, v);
    }
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) roots.push_back(i);
    }
    int k = roots.size();
    cout << k - 1 << endl;
    for (int i = 1; i < k; i++) {
        cout << roots[0] + 1 << " " << roots[i] + 1 << endl;
    }
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
