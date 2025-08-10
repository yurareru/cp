#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAX_N = 100'005;

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int find(int x) { return (e[x] < 0 ? x : e[x] = find(e[x])); }
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

vector<int> sirkel[MAX_N];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    DSU dsu;
    vector<int> bebek(n), gulali(m);
    for (auto& i : bebek) cin >> i;
    for (auto& i : gulali) cin >> i;
    sort(gulali.begin(), gulali.end());
    while (k--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dsu.unite(u, v);
    }
    for (int i = 0; i < n; i++) sirkel[dsu.find(i)].push_back(bebek[i]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sirkel[i].empty()) continue;
        sort(sirkel[i].begin(), sirkel[i].end());
        int sz = sirkel[i].size();
        int median = sz / 2;
        if (sz & 1) {
            int kanan = sirkel[i][median];    // >= median
            int kiri = sirkel[i][median - 1]; // < median;
            int jumlah_kanan = 0, jumlah_kiri = 0;
            for (auto j : sirkel[i]) {
                jumlah_kanan += abs(j - sirkel[i][kanan]);
                jumlah_kiri += abs(j - sirkel[i][kiri]);
            }

            ans += min(jumlah_kanan, jumlah_kiri);
        } else {
            int median_kiri = sirkel[i][median];
            int median_kanan = sirkel[i][median + 1];
            int jumlah_kanan = 0, jumlah_kiri = 0;
            for (auto j : sirkel[i]) {
                jumlah_kanan += abs(j - sirkel[i][median_kiri + 1]);
                jumlah_kiri += abs(j - sirkel[i][median_kiri]);
            }
            int minim = min(jumlah_kanan, jumlah_kiri);
            jumlah_kanan = 0, jumlah_kiri = 0;

            for (auto j : sirkel[i]) {
                jumlah_kanan += abs(j - sirkel[i][median_kanan + 1]);
                jumlah_kiri += abs(j - sirkel[i][median_kanan]);
            }
            ans += min({minim, jumlah_kanan, jumlah_kiri});
        }
    }
    cout << ans << '\n';
}
