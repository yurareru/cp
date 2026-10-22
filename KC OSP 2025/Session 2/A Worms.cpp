#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    v[0] = {0, 0};

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        v[i] = {v[i - 1].second + 1, v[i - 1].second + val};
    }
    int m;
    cin >> m;

    while (m--) {
        int q;
        cin >> q;
        int low = 1, high = n, res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (v[mid].first <= q && q <= v[mid].second) {
                res = mid;
                break;
            } else if (q < v[mid].first) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << res << endl;
    }
}
