#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> arr) {
	int N = arr.size();
	int M = arr[0].size();
	vector<vector<int>> new_arr(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			new_arr[i][j] = arr[N-j-1][i];
		}
	}
	return new_arr;
}

vector<vector<int>> mirror_hor(vector<vector<int>> arr) {
	vector<vector<int>> new_arr = arr;
	reverse(new_arr.begin(), new_arr.end());
	return new_arr;
}

vector<vector<int>> mirror_ver(vector<vector<int>> arr) {
	vector<vector<int>> new_arr = arr;
	for (int i = 0; i < new_arr.size(); i++) {
		reverse(new_arr[i].begin(), new_arr[i].end());
	}
	return new_arr;
}

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	
	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j]; 
		}
	}
	
	vector<string> ops(X);
	for (int i = 0; i < X; i++) {
		cin >> ops[i];
	}
	
	for (string op : ops) {
		if (op == "_") {
            arr = mirror_hor(arr);
        } else if (op == "|") {
            arr = mirror_ver(arr);
        } else if (op == "90") {
            arr = rotate90(arr);
        } else if (op == "180") {
            arr = rotate90(arr);
            arr = rotate90(arr);
        } else if (op == "270") {
            arr = rotate90(arr);
            arr = rotate90(arr);
            arr = rotate90(arr);
        } else {
            cout << "Invalid operator: " << op << "\n";
        }
	}
	
	for (auto row : arr) {
		for (auto val: row) {
			cout << val << " ";
		}
		cout << "\n";
	}
}
