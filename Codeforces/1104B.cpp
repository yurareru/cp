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
    string x;
    cin >> x;
    int round = 0;
    stack<char> s;
    for (char c : x) {
        if (!s.empty() && s.top() == c) {
            s.pop();
            round++;
        } else {
            s.push(c);
        }
    }
    if (round % 2 == 1) cout << "Yes\n";
    else
        cout << "No\n";
}
