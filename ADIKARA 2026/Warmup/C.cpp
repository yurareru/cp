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
    vector<ll> v(n), subtractor;

    for (auto& i : v) cin >> i;

    for (ll i = 1; i <= 1e12; i <<= 1) subtractor.push_back(i);
    reverse(subtractor.begin(), subtractor.end());

    ll count = 0;

    for (int i = 0; i < n; i++) {
        for (auto b : subtractor) {
            if (v[i] - b >= 0) {
                v[i] -= b;
                count++;
            }
        }
    }
    if (count & 1) {
        cout << "ADI\n";
    } else {
        cout << "KARA\n";
    }
}
