// https://cses.fi/problemset/task/1193
// grid, shortest path, backtrack
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MAX_N = 1005;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char dir[] = {'L', 'U', 'R', 'D'};

int n, m;

bool inside(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n; }

string grid[MAX_N];
pii parent[MAX_N][MAX_N];
char move_from_parent[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void solve() {
    pii start, finish;

    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        cin >> grid[y];
        for (int x = 0; x < m; x++) {
            if (grid[y][x] == 'A') start = {x, y};
            if (grid[y][x] == 'B') finish = {x, y};
        }
    }

    queue<pii> bfs;
    bfs.push(start);
    visited[start.first][start.second] = true;

    while (!bfs.empty()) {
        auto [x, y] = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!inside(nx, ny)) continue;
            if (grid[ny][nx] == '#') continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            parent[nx][ny] = {x, y};
            move_from_parent[nx][ny] = dir[i];
            bfs.push({nx, ny});
        }
    }

    if (!visited[finish.first][finish.second]) {
        cout << "NO" << endl;
        return;
    }

    vector<char> path;
    pii cur = finish;
    while (cur != start) {
        char move = move_from_parent[cur.first][cur.second];
        path.push_back(move);
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    for (char c : path) cout << c;
    cout << endl;
}

int main() {
    Bismillah AC;
    solve();
    return 0;
}
