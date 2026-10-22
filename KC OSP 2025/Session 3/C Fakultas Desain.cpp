#include <bits/stdc++.h>
#define ll long long
#define nl endl
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int l = 4, r = n; l < r;) {
        if (is_prime[l]) {
            l += 1;
            continue;
        } else if (is_prime[r]) {
            r -= 1;
            continue;
        }

        if (l + r == n) {
            cout << l << " " << r << nl;
            break;
        } else if (l + r > n) {
            r -= 1;
        } else {
            l += 1;
        }
    }
}
