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

    string s;
    cin >> s;

    deque<char> dq;

    for (char c : s) dq.push_back(c);

    while (!dq.empty()) {
        if (dq.front() == dq.back()) {
            dq.pop_back();
            if (!dq.empty()) dq.pop_front();
        } else if (dq.front() != 'a' && dq.back() == 'a') {
            dq.pop_back();
        } else {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
