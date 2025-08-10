#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, int>
#define pb push_back
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll MAX_N = 100'005;
const ll MAX_M = 200'005;

ll n, m;
vector<ll> adj[MAX_N];
pii value[MAX_N];
bool vis[MAX_N];

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ll v;
        cin >> v;
        value[i] = {i, v};
    }
    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    sort(value + 1, value + n + 1,
         [](auto a, auto b) { return a.second < b.second; });
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        auto [root, price] = value[i];
        if (vis[root]) continue;
        vis[root] = true;
        sum += price;
        queue<ll> bfs;
        // cout << root << " : " << sum << endl;
        bfs.push(root);
        while (!bfs.empty()) {
            ll u = bfs.front();
            bfs.pop();
            for (auto v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                sum += price;
                bfs.push(v);
                // cout << v << " : " << sum << endl;
            }
        }
    }
    cout << sum << endl;
}

int main() {
    Bismillah AC;
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
