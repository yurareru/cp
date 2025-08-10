// https://cses.fi/problemset/task/1091
// binary search
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        h.insert(v);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        auto it = h.upper_bound(x);

        // all tickets are > x
        if (it == h.begin()) {
            cout << "-1\n";
        } else {
            it--;
            cout << *it << '\n';
            h.erase(it);
        }
    }
}
