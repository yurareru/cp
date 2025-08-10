#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int sqr = __gcd(n, m);
        cout << n * m / (sqr * sqr) << endl; 
    }
}