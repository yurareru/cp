// https://cses.fi/problemset/task/3359/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define berak break
#define Bismillah ios_base::sync_with_stdio(false);
#define AC cin.tie(nullptr);

constexpr char nl = '\n';
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr int MAX_N = 3005;

void solve();

int main() {
    Bismillah AC;
    solve();
    return 0;
}

string grid[MAX_N];
int n;

int dx[] = {-1, 0};
int dy[] = {0, -1};

bool between(int l, int x, int r) { return l <= x && x <= r; }

bool inside(int x, int y) {
    return between(0, x, n - 1) && between(0, y, n - 1);
}

string dp[MAX_N][MAX_N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> grid[i];
    fill(&dp[0][0], &dp[MAX_N - 1][MAX_N - 1], "Z");
    dp[0][0] = grid[0][0];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int i = 0; i < 2; i++) {
                int prev_x = x + dx[i];
                int prev_y = y + dy[i];
                if (!inside(prev_x, prev_y)) continue;
                dp[x][y] = min(dp[x][y], dp[prev_x][prev_y] + grid[y][x]);
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}
