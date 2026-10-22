// https://cses.fi/problemset/task/1090
// two pointer
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (auto& i : p) cin >> i;
    sort(p.begin(), p.end());
    int l = 0, r = n - 1, count = 0;
    while (l <= r) {
        if (p[l] + p[r] <= x) {
            l++;
        }
        r--; // heavy child always ride
        count++;
    }
    cout << count << endl;
}
