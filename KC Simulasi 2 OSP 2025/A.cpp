#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    long long max_energy = 0, min_energy = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (long long i = 0; i < n; i++) max_energy += a[i] * b[i];
    for (long long i = 0, j = n - 1; i < n && j >= 0; i++, j--)
        min_energy += a[i] * b[j];
    cout << abs(max_energy - min_energy) << endl;
}
