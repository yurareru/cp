#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	pair<string, int> A[N];
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		A[i] = {str, str.length()};
	}
	
	sort(A, A + N, [](pair<string, int> a, pair<string, int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});
	
	for (auto a : A) {
		cout << a.first << endl;
	}
}
