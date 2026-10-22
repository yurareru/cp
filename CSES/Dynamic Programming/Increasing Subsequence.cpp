// https://cses.fi/problemset/task/1145
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
const int MAX_N = 2e5 + 5;

void solve();

int main() {
    Bismillah AC;
    solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> tails;
    for (auto i : a) {
        auto it = lower_bound(tails.begin(), tails.end(), i);
        // if no element in tails >= i then extend tails
        if (it == tails.end()) {
            tails.pb(i);
        } else {
            // replace to maintain smaller tails
            *it = i;
        }
    }
    cout << tails.size() << nl;
}
