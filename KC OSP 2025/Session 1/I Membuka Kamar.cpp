#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> guests(n);

    for (int i = 0; i < n; i++) {
        cin >> guests[i].first
            >> guests[i].second;
        guests[i].second += guests[i].first;
    }
    sort(guests.begin(), guests.end());
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && guests[i].first - pq.top() > m) pq.pop();
        if (pq.empty() || pq.top() > guests[i].first) {
            ans++;
        } else {
            pq.pop();
        }
        pq.push(guests[i].second);
    }
    cout << ans << endl;
}