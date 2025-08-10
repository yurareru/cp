#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	
	vector<pair<int, int>> A(N + 1, {0, 0}); // first = low & second = high
	for (int i = 1; i <= N; i++) {
		int count;
		cin >> count;
		A[i] = {A[i - 1].second + 1, A[i - 1].second + count};
	}
	
	int Q; cin >> Q;
	while (Q--) {
		int x; cin >> x;
		int low = 1, high = N, ans = -1;
		
		while (low <= high) {
			int mid = (low + high) / 2;
			if (A[mid].first <= x && A[mid].second >= x) {
				ans = mid;
				break;
			} else if (x > A[mid].second) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << ans << endl;
	}
}
