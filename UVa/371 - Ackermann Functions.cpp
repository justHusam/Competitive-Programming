#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll N) {
	ll res = 0;
	do {
		if (N % 2 == 0)
			N /= 2;
		else
			N = 3 * N + 1;
		++res;
	} while (N != 1);
	return res;
}

int main(int argc, char **argv) {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	while (scanf("%lld%lld", &a, &b) > 0 && a != 0 && b != 0) {
		if (a > b)
			swap(a, b);
		ll res = 0, at;
		for (ll i = a; i <= b; i++) {
			ll cur = calc(i);
			if (cur > res) {
				at = i;
				res = cur;
			}
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", a, b, at, res);
	}
	return 0;
}

