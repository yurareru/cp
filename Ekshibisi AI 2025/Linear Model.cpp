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
  while (tc--)
    solve();
  return 0;
}

int M[4] = {95, 86, 68};
int y[4] = {785, 790, 600};

void solve() {
  int n = 3, alpha = 227;
  double L, beta = 6.0;
  for (int i = 1; i <= n; i++) {
    double sum = y[i] - (alpha + beta * M[i]);
    sum *= sum;
    L = sum / 3;
  }
  cout << fixed << setprecision(1) << L << nl;
}
