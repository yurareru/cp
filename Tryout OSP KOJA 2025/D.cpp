#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    int sum_a = 0;
    int sum_b = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            sum_b += a[i];
            sum_a += b[i];
        } else {
            sum_a += a[i];
            sum_b += b[i];
        }
    }
    cout << max(sum_a, sum_b) << endl;
}
