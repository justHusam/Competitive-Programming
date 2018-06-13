#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		ll len = -1;
		ll E = sqrt(2 * n) + 1;
		for (ll r = 2; r <= E && len == -1; ++r) {
			ll x = 2 * n - r * r + r;
			if (x > 0 && x % (2 * r) == 0)
				len = r;
		}
		if (len == -1)
			puts("IMPOSSIBLE");
		else {
			ll a = (2 * n - len * len + len) / (2 * len);
			printf("%d =", n);
			for (int i = 0; i < len; ++i) {
				printf(" %lld", a + i);
				if (i + 1 != len)
					printf(" +");
			}
			puts("");
		}
	}
	return 0;
}
