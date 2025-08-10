#include <bits/stdc++.h>

using namespace std;

int main() {
	string str_in;
	cin >> str_in;

	string str = str_in;
	int l = 1;
	while (l*l < str_in.length()) {
		str += "...............................";
		l++;
	}	
	
	for (int i = 0; i < l; i++) {
		if (i % 2 == 0) {
			for (int j = i * l; j < (i + 1) * l; j++) {
				cout << str[j];
			}
		} else {
			for (int j = (i + 1) * l - 1; j >= i * l; j--) {
				cout << str[j];
			}
		}
		cout << endl;
	}
}
