// https://cses.fi/problemset/task/1094
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& i : x) cin >> i;
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (x[i] < x[i - 1]) {
            int diff = x[i - 1] - x[i];
            count += diff;
            x[i] += diff;
        }
    }
    cout << count << '\n';
}
