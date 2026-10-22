// https://cses.fi/problemset/task/1713
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
    while (tc--) {
        int x;
        cin >> x;
        int count = 0;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                (i * i == x) ? count++ : count += 2;
            }
        }
        cout << count << endl;
    }
}
