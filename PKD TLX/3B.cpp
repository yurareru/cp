#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	int A[N];
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	
	double median = 0;
	if (N % 2 == 1) {
		median = A[N / 2];
	} else {
		median = (A[N / 2 - 1] + A[N / 2]) / 2.0;
	}
	cout << fixed << setprecision(1) << median;
}
