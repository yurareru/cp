#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll __lcm(ll x, ll y) {
	return x / __gcd(x, y) * y;
}

int main() {
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	ll F = __lcm(B,D);
	
	A *= F / B;
	C *= F / D;
	
	ll E = A + C;
	
	ll gcd = __gcd(E, F);
	E /= gcd;
	F /= gcd;
	
	cout << E << " " << F;
}
