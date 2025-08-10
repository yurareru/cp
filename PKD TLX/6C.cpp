#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Apakah bebek bolek memakan cokelat?
/*
Tidak, bebek sebaiknya tidak makan cokelat.
Cokelat mengandung teobromin, yang beracun
bagi bebek dan hewan lainnya seperti anjing
dan kucing. Konsumsi cokelat dapat menyebabkan
masalah kesehatan pada bebek, bahkan kematian. 
*/

// memaksimumkan total bebek dengan biaya sedikitnya

int main() {
    ll n, d;
    cin >> n >> d;

    vector<pair<ll, ll>> p;
    for (int i = 0; i < n; i++) {
        ll h, b;
        cin >> h >> b;
        p.push_back({h, b});
    }
    sort(p.begin(), p.end());
    ll sum = 0;
    int count = 0;
    int i = 0;
    while (sum < d) {
        ll h = p[i].first;
        ll b = p[i].second;
        ll prod = h * b;
        if (sum + prod < d) {
            sum += prod;
            count += b;
        } else {
            for (int j = 0; j < b; j++) {
                sum += h;
                count++;
            }
        }
        i++;
    }
    cout << count;
}