#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define berak break
#define nl '\n'
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_LENGTH = 1e4 + 5;

// dp(ith digit, digit sum % d, tight)
int dp[MAX_LENGTH][105][2];
void solve() {
    string k;
    int d;
    cin >> k >> d;
    int len = k.size();
    dp[0][0][1] = 1;
    for (int pos = 0; pos < len; pos++) {
        for (int sum_mod = 0; sum_mod < d; sum_mod++) {
            for (int tight = 0; tight <= 1; tight++) {
                // if tight, only allow [0,k_pos]
                int limit = (tight ? k[pos] - '0' : 9);
                for (int digit = 0; digit <= limit; digit++) {
                    int next_tight = (tight && digit == limit ? 1 : 0);
                    int next_sum_mod = (sum_mod + digit) % d;
                    dp[pos + 1][next_sum_mod][next_tight] +=
                        dp[pos][sum_mod][tight];
                    dp[pos + 1][next_sum_mod][next_tight] %= MOD;
                }
            }
        }
    }
    cout << (dp[len][0][0] + dp[len][0][1] - 1 + MOD) % MOD << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
