#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int max = 3 * n;
        int A[max];
        for (int i = 0; i < max; i++) {
            cin >> A[i];
        }
        sort(A, A + max);
        int sum = 0;
        for (int i = max - 2; i >= n; i-=2) sum += A[i];
        
        cout << sum << endl;
    }
}