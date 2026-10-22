#include <bits/stdc++.h>

using namespace std;

int len[200005];

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        cin >> len[i];
    }
    sort(len + 1, len + n + 1);
    // l <= 2(len[i] + len[j]) <= r
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int total = 2 * len[i] + 2 * len[j];
            if (l <= total && total <= r) count++;
        }
    }
    cout << count << endl;
}
