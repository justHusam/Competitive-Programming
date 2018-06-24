#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void update(ll &a, ll &b) {
	ll gcd = __gcd(a, b);
	a /= gcd;
	b /= gcd;
}

ll nCk(ll n, ll k) {
	ll num = 1, den = 1;
	if ((k << 1) > n)
		k = n - k;
	for (int i = k; i >= 1; --i) {
		ll a = n - k + i, b = i;
		update(a, b);
		update(num, b);
		update(den, a);
		num *= a;
		den *= b;
	}
	return num / den;
}

int main(int argc, char **argv) {
	ll n, k;
	while (scanf("%lld%lld", &n, &k) && n != 0) {
		printf("%lld\n", nCk(n, k));
	}
	return 0;
}
