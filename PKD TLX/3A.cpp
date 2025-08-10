#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, X; cin >> N >> X;
	
	int A[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	
	pair<int, int> lowest = {abs(X - A[0]), A[0]};
	
	for (int i = 1; i < N; i++) {
		int selisih = abs(X- A[i]);
		if(selisih < lowest.first || selisih == lowest.first && A[i] < lowest.second) lowest = {selisih, A[i]};
	}
	
	cout << lowest.second;
}
