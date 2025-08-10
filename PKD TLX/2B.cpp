#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int count = 0;
	
	vector<string> res;
	
	while (N % 2 == 0) {
		N /= 2;
		count++;
	}
	if (count == 1) {
		res.push_back("2");
	} else if (count > 1) {
		res.push_back("2^" + to_string(count));
	}
	
	for (int i = 3; i * i <= N; i += 2) {
		count = 0;
		while (N % i == 0) {
			N /= i;
			count++;
		}
		if (count == 1) {
			res.push_back(to_string(i));
		} else if (count > 1) {
			res.push_back(to_string(i) + "^" + to_string(count));
		}
	}
	if (N > 2) {
		res.push_back(to_string(N));
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1) {
			cout << " x ";
		}
	}
}
