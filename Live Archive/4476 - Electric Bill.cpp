#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll v) {
	ll res = 0;
	res += min(v, 100LL) * 2;
	res += max(0LL, min(v - 100, 9900LL)) * 3;
	res += max(0LL, min(v - 10000, 990000LL)) * 5;
	res += max(0LL, v - 1000000) * 7;
	return res;
}

ll BS(ll v) {
	ll l = 1, r = 2e9, res = -1;
	while (l <= r) {
		ll m = (l + r) >> 1;
		ll need = calc(m);
		if (need == v) {
			res = m;
			break;
		}
		if (need < v)
			l = m + 1;
		else
			r = m - 1;
	}
	return res;
}

int main() {
//	freopen("a", "r", stdin);
	int a, b;
	while (scanf("%d%d", &a, &b) && (a != 0 || b != 0)) {
		ll v = BS(a);
		ll l = 1, r = (v + 1) / 2, res = -1;
		while (l <= r) {
			ll m = (l + r) >> 1;
			ll x = calc(m), y = calc(v - m);
			ll diff = max(x, y) - min(x, y);
			if (diff == b) {
				res = min(m, v - m);
				break;
			}
			if (diff > b)
				l = m + 1;
			else
				r = m - 1;
		}
		printf("%lld\n", calc(res));
	}
	return 0;
}
