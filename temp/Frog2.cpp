#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  vector <int> dp(n, 1e9);
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 2; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i-j < 0) break;
      dp[i] = min(dp[i-j] + abs(h[i]-h[i-j]), dp[i]);
    }
  }
  cout << dp[n-1];
}
