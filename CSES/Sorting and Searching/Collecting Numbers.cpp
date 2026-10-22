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
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pos[t] = i;
    }
    int pass = 1;
    for (int i = 2; i <= n; i++)
        if (pos[i - 1] > pos[i]) pass++;
    cout << pass << endl;
}
