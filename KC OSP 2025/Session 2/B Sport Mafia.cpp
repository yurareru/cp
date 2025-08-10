#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, k; cin >> n >> k;
    ll x = n + k;
    ll count = 0;

    while(x != (count * (count + 1) ) /2 )
    {
        count++;
        x--;
    }
    cout << n - count << endl;
}