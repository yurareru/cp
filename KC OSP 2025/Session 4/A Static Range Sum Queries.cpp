#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, q;
    cin >> n >> q;
    int x[n+1];
    x[0] = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        x[i] = x[i-1] + val;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << x[b] - x[a-1] << endl;
    }
}