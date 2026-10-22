#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200005;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    bool has_o = 0, has_s = 0, has_n = 0, has_p = 0, prev_p = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O' && !prev_p) {
            has_o = 1;
            count++;
        } else if (s[i] == 'S' && !prev_p) {
            has_s = 1;
            count++;
        } else if (s[i] == 'N' && !prev_p) {
            has_n = 1;
            count++;
        } else if (s[i] == 'P') {
            has_p = 1;
            prev_p = 1;
            count++;
        }
    }
    if (has_o && has_s && has_n && has_p) {
        cout << count;
    } else {
        cout << "-1";
    }
}
