#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define berak break
#define Bismillah ios_base::sync_with_stdio(false);
#define AC cin.tie(nullptr);
#define F first
#define S second

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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    sort(a.begin(), a.end());
    vector<pair<int, pii>> b(n);
    b[0] = {a[0].S, {1, 1}};
    for (int i = 1; i < n; i++) {
        if (a[i].F != a[i - 1].F) {
            b[i] = {a[i].S, {b[i - 1].S.S + 1, b[i - 1].S.S + 1}};
            continue;
        }
        int j = 1;
        while (a[i].F == a[i - j].F) {
            if (j == 1) b[i] = {a[i].S, {b[i - j].S.F, b[i - j].S.S + 1}};
            b[i - j].S = {b[i].S.F, b[i].S.S};
            j++;
        }
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        cout << b[i].S.F << " " << b[i].S.S << nl;
    }
}
