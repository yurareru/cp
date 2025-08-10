#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string str1, str2, str3;
    
    cin >> str1 >> str2 >> str3;

    unordered_map<char, char> A;
    unordered_map<char, char> B;

    for (int i = 0; i < N; i++) {
        char a = str1[i];
        char b = str2[i];

        if (A.count(a)) {
            if (A[a] != b) {
                cout << "Pak Dengklek bingung" << endl;
                return 0;
            }
        } else {
            A[a] = b;
        }

        if (B.count(b)) {
            if (B[b] != a) {
                cout << "Pak Dengklek bingung" << endl;
                return 0;
            }
        } else {
            B[b] = a;
        }
    }

    string res;
    for (int i = 0; i < N; i++) {
        char c = str3[i];
        if (B.count(c)) {
            res += B[c];
        } else {
            res += '?';
        }
    }

    cout << res << endl;
}

