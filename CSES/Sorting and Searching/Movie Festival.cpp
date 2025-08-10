// https://cses.fi/problemset/task/1629
// greedy, activity selection
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<pii> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a});
    }
    // sort by fastest ending movie
    sort(movies.begin(), movies.end());
    int prev_end = 0, count = 0;
    for (auto [end, start] : movies) {
        if (start >= prev_end) {
            count++;
            prev_end = end;
        }
    }
    cout << count << endl;
}
