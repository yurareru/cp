#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, b; cin >> n >> b;

    int h[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h, h + n, greater<int>());
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        sum += h[i];
        count++;
        if (sum >= b) break;
    }

    cout << count << endl;
}