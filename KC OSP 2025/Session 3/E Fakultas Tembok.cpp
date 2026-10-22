#include <bits/stdc++.h>
#define nl endl

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b, start, end;
    cin >> a >> b >> start >> end;

    int x = lcm(a, b);

    int first = ((start + x - 1) / x) * x;
    int count = 0;

    if (first <= end) {
        count = (end - first) / x + 1;
    }

    cout << count << nl;
}
