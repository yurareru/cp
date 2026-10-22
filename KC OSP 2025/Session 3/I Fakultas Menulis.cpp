#include <bits/stdc++.h>
#define nl '\n'

using namespace std;

const int MOD = 998244353;

int main() {
    int q;
    cin >> q;

    string s = "1";
    for (int i = 0; i < q; i++) {
        int val;
        cin >> val;
        if (val == 1) {
            int x;
            cin >> x;
            s += to_string(x);
        } else if (val == 2) {
            s.erase(0, 1);
        } else if (val == 3) {
            cout << stoll(s) % MOD << nl;
        }
    }
}
