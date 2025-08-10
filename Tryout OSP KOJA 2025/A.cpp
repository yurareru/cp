#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (auto& i : t) cin >> i;
    sort(t.begin(), t.end());

    int l = 0, r = n - 1, diff = 0;

    for (int i = 0; i < n - 1; i++) {
        diff += t[i + 1] - t[i];
    }
    while (l < r + 1 && m) {
        int diff_l = t[l + 1] - t[l];
        int diff_r = t[r] - t[r - 1];
        if (diff_r > diff_l) {
            diff -= diff_r;
            r--;
        } else {
            diff -= diff_l;
            l++;
        }
        m--;
    }
    cout << diff << endl;
}

/*
7 4
3 22 17 9 19 31 24
*/

/*
15 10
37 29 2 12 98 21 19 87 78 9 56 35 62 25 77
*/
