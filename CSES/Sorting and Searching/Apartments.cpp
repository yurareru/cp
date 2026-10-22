// https://cses.fi/problemset/task/1084
// two pointer
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (b[j] < a[i] - k) j++; // too small
        else if (b[j] > a[i] + k)
            i++; // too big
        else {
            count++;
            i++;
            j++;
        }
    }
    cout << count << endl;
}
