#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    pair<string, int> s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i + 1;
    }
    sort(s, s + n, [m](const auto a, const auto b) {
        for (int i = 0; i < m; i++) {
            if (a.first[i] == b.first[i]) continue;

            if (i % 2) return a.first[i] > b.first[i];
            return a.first[i] < b.first[i];
        }
    });
    for (int i = 0; i < n; i++) {
        cout << s[i].second << " ";
    }
}
