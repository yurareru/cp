// https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 1e7;

unordered_map<ll, ll> memo;

ll f(ll n) {
    if (n < 0) n = abs(n);
    if (n == 1) return 1;
    cout << n << " ";
    if (memo.count(n)) return memo[n];
    if (n & 1) {
        memo[n] = f(3 * n + 1);
    } else {
        memo[n] = f(n / 2);
    }
    return memo[n];
}

int main() {
    Bismillah AC;
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
