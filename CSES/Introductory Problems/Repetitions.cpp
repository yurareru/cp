// https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define nl '\n'
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    string s;
    cin >> s;

    char temp = s[0];
    int count = 1;
    int maxs = 0;
    int n = s.size();
    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (temp == s[i]) {
            count++;
        } else {
            count = 1;
        }
        maxs = max(count, maxs);
        temp = s[i];
    }
    cout << maxs << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
