#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), p(n, 0), t(n, 0);
    for (auto& i : a) cin >> i;
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start + len <= n; start++) {
            int mask = 0;
            for (int i = 0; i < len; i++) {
                mask |= (1 << (start + i));
            }
            int permen = 0, toples = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    // cout << a[i] << " ";
                    permen += a[i];
                    toples++;
                }
            }
            // cout << " | ";
            // cout << permen << " " << toples << "\n";
            if (permen % toples == 0) {
                for (int i = 0; i < toples; i++) {
                    p[i] += permen / toples;
                    t[i]++;
                    // cout << i << " : " << p[i] << " " << t[i] << "\n";
                }
            } else {
                p[0] += permen;
                t[0] += toples;
                // cout << 0 << " : " << p[0] << " " << t[0] << "\n";
            }
            // cout << "\n";
        }
    }
    for (auto i : p) cout << i << " ";
    cout << '\n';
    for (auto i : t) cout << i << " ";
}
