#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d; cin >> n >> d;
    deque<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int count = 0;

    while (!p.empty()) {
        int max_power = p.back();
        int needed = (d + max_power) / max_power;
        if (p.size() >= needed) {
            for (int i = 0; i < needed - 1; i++) {
                p.pop_front();
            }
            p.pop_back();
            count++;
        } else {
            break;
        }
    }
    cout << count;
}