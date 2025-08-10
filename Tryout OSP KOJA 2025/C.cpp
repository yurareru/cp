#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int size = a.size();
    while (l < r) {
        if (a[l] == a[r]) {
            r--;
            continue;
        }
        size -= 2;
        l++, r--;
    }
    cout << size << endl;
}
/*
7
3 5 2 1 1 2 3
*/
