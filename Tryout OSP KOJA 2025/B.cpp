#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll digsum(string x) {
    ll sum = 0;
    for (int i = x.size() - 1; i >= 0; i--) sum += x[i] - '0';
    return sum;
}

int main() {
    string s;
    cin >> s;
    string maxs = "-1";
    for (int i = s.size() - 1; i > 0; i--) {
        string sub = s.substr(0, i);
        if (sub.back() % 2 == 0) continue;
        if (digsum(sub) % 2 == 0) {
            maxs = max(sub, maxs);
        }
    }
    cout << maxs;
}

/*
134924587292
82802468i2
7846543182054256446358
*/
