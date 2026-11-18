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
constexpr int MAX_N = 1005;

void solve();

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<string> pwd;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "cd") {
            string path;
            cin >> path;
            stringstream ss(path);
            string dir;
            while (getline(ss, dir, '/')) {
                if (dir == "..") pwd.pop_back();
                else if (dir == "")
                    pwd.clear();
                else
                    pwd.pb(dir);
            }
        }
        if (s == "pwd") {
            cout << "/";
            for (string dir : pwd) cout << dir << "/";
            cout << nl;
        }
    }
}
