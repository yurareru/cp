#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n; cin >> n;

    vector<int> v1(n);
    vector<int> v2(n);

    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += v1[i] * v2[i];
    }
    cout << sum << endl;
}