#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define berak break
#define Bismillah ios_base::sync_with_stdio(false);
#define AC cin.tie(nullptr);

constexpr char nl = '\n';
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr int MAX_N = 1005;

void solve();

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

void solve() {
    string a, b, ans = "";
    cin >> a >> b;
    if (a.size() < b.size()) {
        a = string(b.size() - a.size() + 1, '0') + a;
        b = '0' + b;
    } else {
        b = string(a.size() - b.size() + 1, '0') + b;
        a = '0' + a;
    }
    int n = a.size();
    vector<int> c(n, 0);
    // cout << nl << a << nl << b << nl << nl;
    for (int i = n - 1; i >= 0; i--) {
        int t = a[i] - '0' + b[i] - '0' + c[i];
        if (t > 9) {
            c[i - 1] = t / 10;
            // cout << c[i - 1] << " ";
        }
        // cout << t % 10 << nl;
        ans += to_string(t % 10);
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() < 16) {
        cout << stoll(ans);
        return;
    }
    cout << ans << nl;
}
