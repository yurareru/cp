#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    bool prime[705];
    memset(prime, 1, sizeof prime);

    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= 700; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 700; j += i) {
            prime[j] = 0;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (prime[a[i]]) count++;
        for (int j = i; j < n; j++) {
            if (i == j) continue;
            if (prime[a[j] + a[i]]) count++;
        }
    }
    cout << count << endl;
}
