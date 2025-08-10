#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	
	int A[N];
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	int Q; cin >> Q;
	while (Q--) {
		int x, y; cin >> x >> y;
		cout << upper_bound(A, A + N, y) - upper_bound(A, A + N, x) << endl;
	}
}
