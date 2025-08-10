#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> comb;

void generate(int start, int depth) {
	if (depth == K) {
		for (int x : comb) cout << x << ' ';
		cout << endl;
		return;
	}

	for (int i = start; i <= N; i++) {
		comb.push_back(i);
		generate(i + 1, depth + 1);
		comb.pop_back();
	}
}

int main() {
	cin >> N >> K;
	generate(1, 0);
}
