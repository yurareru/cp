#include <bits/stdc++.h>

using namespace std;

int main() {
	string A, B; cin >> A >> B;
	
	bool bisa_ngga = false;
	
	for (int i = 0; i < A.length(); i++) {
		string C = A;
		C.erase(i, 1);
		if (C == B) {
			bisa_ngga = true;
			break;
		}
	}	
	
	cout << (bisa_ngga ? "Tentu saja bisa!" : "Wah, tidak bisa :(");
}
