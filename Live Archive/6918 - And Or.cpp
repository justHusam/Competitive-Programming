#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> solve(ll n) {
	if (n <= 1)
		return vector<ll>(1, n);
	ll p = 1;
	while (p <= n)
		p <<= 1;
	p >>= 1;
	--p;
	int bits = 0;
	for (ll temp = p; temp > 0; temp >>= 1)
		++bits;
	vector<ll> res(bits, (p + 1) / 2);
	ll rem = n - p;
	p = 1;
	for (int i = 0; i < bits; ++i, p <<= 1) {
		ll ones = rem / p / 2 * p;
		if ((rem / p) & 1)
			ones += rem % p;
		res[i] += ones;
	}
	res.push_back(rem);
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		vector<ll> x = solve(a - 1);
		vector<ll> y = solve(b);
		for (size_t i = 0; i < x.size(); ++i)
			y[i] -= x[i];
		ll O = 0, A = 0, p = 1;
		for (size_t i = 0; i < y.size(); ++i, p <<= 1)
			if (y[i] != 0)
				O += p;
		p = 1;
		for (size_t i = 0; i < y.size(); ++i, p <<= 1)
			if (y[i] == b - a + 1)
				A += p;
		printf("Case %d: %lld %lld\n", cas++, O, A);
	}
	return 0;
}
