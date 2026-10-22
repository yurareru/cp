#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define nl '\n'
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    ll k;
    cin >> k;

    ll digit = 1;
    ll count = 9;
    ll start = 1;

    while (k > digit * count) {
        k -= digit * count;
        digit++;
        count *= 10;
        start *= 10;
    }

    start += (k - 1) / digit;
    string s = to_string(start);
    cout << s[(k - 1) % digit] << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
