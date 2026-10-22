// https://cses.fi/problemset/task/1192
// grid, connectivity
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 1005;

int n, m;
string grid[MAX_N];
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

bool between(int l, int x, int r) { return l <= x && x <= r; }

bool inside(int x, int y) {
    return between(0, x, n - 1) && between(0, y, m - 1);
}

bool vis[MAX_N][MAX_N];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!inside(nx, ny)) continue;
        if (grid[nx][ny] == '#') continue;
        if (vis[nx][ny]) continue;
        dfs(nx, ny);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> grid[i];
    int count = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (!vis[x][y] && grid[x][y] != '#') {
                dfs(x, y);
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {
    Bismillah AC int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
