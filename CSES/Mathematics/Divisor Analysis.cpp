// https://cses.fi/problemset/task/2182
#include <bits/stdc++.h>
#define ll long long
#define berak break

using namespace std;

const int MOD = 1'000'000'007;

ll power(ll a, ll b) {
    if (b == 0) return 1;
    ll res = power(a, b / 2);
    res = res * res % MOD;
    if (b & 1) res = res * a % MOD;
    return res;
}

int main() {
    int tc = 1;
    cin >> tc;
    ll n = 1;
    while (tc--) {
        int x, k;
        cin >> x >> k;
        n *= power(x, k);
    }

    ll count = 0;
    ll sum = 0;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                count++;
                sum += i;
            } else {
                int j = n / i;
                count += 2;
                sum += i + j;
            }
            sum %= MOD;
        }
    }
    cout << count << " " << sum << " " << power(n, count / 2) << endl;
}
