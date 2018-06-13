#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	ll l, r;
	while (scanf("%lld%lld", &l, &r) > 0 && (l != 0 || r != 0)) {
		ll x = l, y = r, res = 0;
		while (x % 5 != 0)
			++x;
		if (x > l)
			++res;
		while (y % 5 != 0)
			--y;
		if (x < y) {
			res += (y - x) / 5 + 1;
		} else if (x == y)
			++res;
		printf("%lld\n", res);
	}
	return 0;
}
