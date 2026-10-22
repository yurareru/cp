// https://cses.fi/problemset/task/1095
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1'000'000'007;

int power(int a, int b) {
    if (b == 0) return 1;
    int res = power(a, b / 2);
    res = res * res % MOD;
    if (b & 1) res = res * a % MOD;
    return res;
}

signed main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << power(a, b) << endl;
    }
}
