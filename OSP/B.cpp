#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, p, l;
    cin >> n >> p >> l;
    if (p == l) {
        ll i = 1;
        while (n * p * l > i * i) {
            i++;
        }
        cout << i << endl;
    } else if (n == p && l == 1) {
        cout << n << endl;
    } else {
    }
}
