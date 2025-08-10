#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
	int n, m; cin >> n >> m;

	if (n > m) {
		swap(n, m);
	}

	cout << m * (m + 1) / 2 + (m + n) * (n - 1) << endl;
}

int main() {
	Bismillah AC;
	int tc = 1;
	// cin >> tc;
	while (tc--) solve();
	return 0;
}
