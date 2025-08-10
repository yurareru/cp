#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<tuple<ll, ll, int>> kesuksesan;
	
	for (int i = 1; i <= N; i++) {
		ll a, b;
		cin >> a >> b;
		kesuksesan.push_back({a, b, i});
	}
	
	sort(kesuksesan.begin(), kesuksesan.end(), [](auto x, auto y) {
		ll a1, b1, i1;
		ll a2, b2, i2;
		tie(a1, b1, i1) = x;
		tie(a2, b2, i2) = y;
		ll c1 = a1 * (a2 + b2);
		ll c2 = a2 * (a1 + b1);
		if (c1 == c2) {
			return i1 < i2;
		}
		return c1 > c2;
	});
	
	for (auto [a, b, i] : kesuksesan) cout << i << " ";
}
