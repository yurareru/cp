// https://cses.fi/problemset/task/3359
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define nl '\n'
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 3005;

ll add(ll a, ll b) { return (a + b) % MOD; }
int dx[] = {-1, 0}; // l, u
int dy[] = {0, -1};

int n;
int between(int l, int x, int r) { return l <= x && x <= r; }
bool inside(int x, int y) {
    return between(0, x, n - 1) && between(0, y, n - 1);
}
string grid[MAX_N];
int dp[MAX_N][MAX_N];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> grid[i];
    fill(&dp[0][0], &dp[MAX_N - 1][MAX_N - 1], INF);
    dp[0][0] = grid[0][0];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (!inside(x, y)) continue;
            for (int i = 0; i < 2; i++) {
                int prev_x = x + dx[i];
                int prev_y = y + dy[i];
                if (!inside(prev_x, prev_y)) continue;
                dp[x][y] = min(dp[x][y], dp[prev_x][prev_y] + grid[y][x]);
            }
        }
    }

    vector<pii> path;
    int x = n - 1, y = n - 1;
    while (x > 0 || y > 0) {
        path.pb({x, y});
        if (x == 0) y--;
        else if (y == 0)
            x--;
        else if (dp[x][y - 1] < dp[x - 1][y])
            y--;
        else
            x--;
    }
    path.pb({0, 0});
    reverse(path.begin(), path.end());

    for (auto [px, py] : path) cout << grid[py][px];
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
