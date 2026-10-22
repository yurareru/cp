// https://cses.fi/problemset/result/13918216/
// suffix sum, sliding window
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    ll xs[n + 1], sufx[n + 5] = {};
    xs[1] = x;

    for (ll i = 2; i <= n; i++) {
        xs[i] = (a * xs[i - 1] + b) % c;
    }
    sufx[n] = xs[n];
    for (ll i = n - 1; i >= 1; i--) {
        sufx[i] = xs[i] + sufx[i + 1];
    }
    ll ans = 0;
    for (ll i = 1, j = k + 1; j <= n + 1; i++, j++) {
        ans = ans ^ (sufx[i] - sufx[j]);
    }
    cout << ans << endl;
}
