#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		int mx = (int) sqrt(c);
		bool can = false;
		for (ll x = -mx; x * x <= c && !can; ++x)
			for (ll y = -mx; y * y <= c && !can; ++y) {
				ll z = a - x - y;
				if (x == 0 || y == 0 || z == 0 || z == x || z == y || x == y)
					continue;
				if (x * y * z == b && x * x + y * y + z * z == c) {
					printf("%lld %lld %lld\n", x, y, z);
					can = true;
				}
			}
		if (!can)
			puts("No solution.");
	}
	return 0;
}
