#include <bits/stdc++.h>

#define ll long long

using namespace std;
bool prime[300'000];
int main() {
    ll n;
    cin >> n;
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        for (ll j = i * i; j <= n; j += i) {
            prime[j] = 0;
        }
    }
    ll best = 0;
    ll best_type = 2;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] && n % i == 0) {
            ll kemasan = n / i;
            ll telur = kemasan * i * i;
            ll count = 0;
            for (ll j = 1; j * j <= telur; j++) {
                ll k = telur / j;
                if (telur % j == 0) {
                    count += 2;
                    if (j == k) count--;
                    // cout << j << " " << k << endl;
                }
            }
            if (count > best) {
                best = count;
                best_type = i;
            }
            // cout << i << " " << count << endl << endl;
        }
    }
    cout << best_type << endl;
}
