#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	int count = 0;
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (A[j] > A[j+1]) {
				swap(A[j], A[j+1]);
				count++;
			}
		}
	}
	cout << count;
}
