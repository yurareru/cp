#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e6;

ll bpow(ll x, ll y) {
    if (y == 0) return 1;
    ll res = bpow(x, y / 2) % MOD;
    if (y % 2 == 0) return res * res % MOD;
    else return res * res % MOD * x % MOD;
}

int main() {
    ll A, B; cin >> A >> B;
    ll result = bpow(A, B);
    if (result > 0 && result < 1000000) {
        cout << result;
    } else {
        cout << setw(6) << setfill('0') << result;
    }
}