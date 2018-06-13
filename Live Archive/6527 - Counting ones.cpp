#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n) {
	if (n <= 1)
		return n;
	ll power = 1;
	while (power <= n)
		power <<= 1;
	power >>= 1;
	ll bits = 0, temp = power - 1;
	while (temp > 0) {
		++bits;
		temp >>= 1;
	}
	ll res = bits * power / 2, len = n - power + 1, p = 1;
	while (bits-- > 0) {
		ll at = len / p;
		res += at / 2 * p;
		if ((at & 1) == 1)
			res += len % p;
		p *= 2;
	}
	res += len;
	return res;
}

int main(int argc, char **argv) {
	ll a, b;
	while (scanf("%lld%lld", &a, &b) > 0)
		printf("%lld\n", solve(b) - solve(a - 1));
	return 0;
}
