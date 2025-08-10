#include <bits/stdc++.h>
#define berak break
#define int long long

using namespace std;

const int MOD = 1'000'000'007;
const int MAXY = 100'007;

int dp[MAXY];

signed main() {
	int b; string y;
	cin >> b >> y;
	dp[0] = 1;
	int n = y.length();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 8 && i - j >= 0; j++) {
			if (j > 1 && y[i - j] == '0') berak;
			int cur = 0;
			for (int k = i - j; k < i; k++) {
				cur = cur * 10 + (y[k] - '0');
				if (cur >= b) berak;
			}
			if (cur < b) dp[i] = (dp[i] + dp[i-j]) % MOD;
		}
	}
	cout << dp[n] << endl;
}
