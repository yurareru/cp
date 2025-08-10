#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1005;

int C[MAXN][MAXN];
void compute_binom(int n) {
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
}

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	
	int count = 0;
	
	compute_binom(N);
	
	for (int i = A; i <= B; i++) {
		count = (count + C[N][i]) % MOD;
	}
	
	cout << count;	
}
