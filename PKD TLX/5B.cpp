#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

bool comp(int x, int y) {
    if (x < y) {
        cnt++;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, comp); // not work, use mergesort instead
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}