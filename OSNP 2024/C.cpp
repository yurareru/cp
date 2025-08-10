#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100'007;
int arr[MAXN];

int potong(int N, int batas) {
	int total = 0;
	for (int i = 0; i < N; i++) {
		if(arr[i] > batas) total += arr[i] - batas;
	}
	return total;
}

signed main () {
	int N, M;
	cin >> N >> M;
	int tinggi_maks = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		tinggi_maks = max(tinggi_maks, arr[i]);
	}
	
	int low = 0, high = tinggi_maks, keluar = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int panjang_kayu = potong(N, mid);
		if (panjang_kayu >= M) {
			keluar = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}	
	cout << keluar << endl;
}
