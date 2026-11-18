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
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.pb(x);
    }
    int sereja = 0;
    int dima = 0;
    while (!v.empty()) {
        if (v.front() > v.back()) {
            sereja += v.front();
            v.erase(v.begin());
        } else {
            sereja += v.back();
            v.pop_back();
        }
        if (v.empty()) berak;
        if (v.front() > v.back()) {
            dima += v.front();
            v.erase(v.begin());
        } else {
            dima += v.back();
            v.pop_back();
        }
    }
    cout << sereja << " " << dima << nl;
}
