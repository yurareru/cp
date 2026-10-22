#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1000000007LL;

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    a %= MOD;
    ll res = binpow(a, b / 2);
    res = (res * res) % MOD;
    if (b % 2 == 1) {
        res = (res * a) % MOD;
    }
    return res;
}

int main() {
    ll n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << binpow(a, b) << endl;
    }
}
