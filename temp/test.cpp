#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;

ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    a %= MOD;
    ll res = binpow(a, n / 2);
    res = res * res % MOD;
    if (n & 1) res = res * a % MOD;
    return res;
}

void solve() {
    int n;
    cin >> n;
    cout << n;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
