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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    int count = 0;
    while (!v.empty()) {
        int prev = v.front();
        v.erase(v.begin());
        int i = 0;
        while (i < int(v.size())) {
            if (prev < v[i]) {
                prev = v[i];
                v.erase(v.begin() + i);
                i = 0;
            } else
                i++;
        }
        count++;
    }
    cout << count << nl;
}
