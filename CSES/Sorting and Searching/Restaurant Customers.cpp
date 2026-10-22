// https://cses.fi/problemset/task/1619
// sweep line
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define pb push_back

int main() {
    int n;
    cin >> n;
    vector<pii> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.pb({a, 1});
        events.pb({b, -1});
    }
    sort(events.begin(), events.end());
    int max_cust = 0, cur_cust = 0;
    for (auto [time, type] : events) {
        cur_cust += type;
        max_cust = max(max_cust, cur_cust);
    }
    cout << max_cust << endl;
}
