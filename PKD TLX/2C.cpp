#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> K(T);
    for (int i = 0; i < T; i++) {
        cin >> K[i];
    }

    const int LIMIT = 1000100;
    vector<bool> is_prime(LIMIT, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i < LIMIT && primes.size() < 77777; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < T; i++) {
        cout << primes[K[i] - 1] << "\n";
    }

    return 0;
}

