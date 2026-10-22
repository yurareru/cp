#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n + 1);

    int maks = 1;

    a[0].first = 0;
    a[0].second = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        if (a[i - 1].first < a[i].first) {
            a[i].second = a[i - 1].second + 1;
        } else {
            a[i].second = 1;
        }
        maks = max(maks, a[i].second);
    }
    cout << maks << endl;
}
