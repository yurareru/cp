#include <bits/stdc++.h>

using namespace std;

int main() {
	int R, C;
	cin >> R >> C;
	
	string arr[R];
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	
	string full_one(C, '1');
	string full_zero(C, '0');
	
	int lowest = -1;
	
	for (int i = 0; i < R; i++) {
		if (arr[i] == full_one) {
			arr[i] = full_zero;
			lowest = i;
		}
	}
	
	if (lowest != -1) {
		for (int i = lowest - 1; i >= 0; i--) {
			for (int j = 0; j < C; j++) {
				int k = i;
				while(arr[k][j] == '1' && arr[k+1][j] == '0') {
					arr[k][j] = '0';
					arr[k+1][j] = '1';
					k++;
				}
			}
		}	
	}
	for (string row : arr) {
		cout << row << "\n";
	}
}
