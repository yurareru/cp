#include <bits/stdc++.h>
#define ll long long
#define nl endl

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll first_pair = 1;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            first_pair = max(first_pair, i);
        }
    }

    ll second_pair = n / first_pair;

    cout << first_pair + second_pair - 2 << nl;
}
