#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(long long x) {
    string s = to_string(x);
    long long l = 0, r = s.size() - 1;
    while (l <= r) {
        if (s[l] == '0') l++;
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> count(k, 0);
    for (long long i = 0; i < k; i++) {
        for (long long j = i; j <= n; j += k) {
            if (is_palindrome(j)) count[i]++;
        }
    }
    for (auto i : count) cout << i << " ";
}
