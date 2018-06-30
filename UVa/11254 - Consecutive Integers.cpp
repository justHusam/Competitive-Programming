#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != -1) {
		ll len = -1;
		for (ll r = sqrt(2 * n) + 1; r >= 1 && len == -1; --r) {
			ll x = 2 * n - r * r + r;
			if (x > 0 && x % (2 * r) == 0)
				len = r;
		}
		int a = (2 * n - len * len + len) / (2 * len);
		printf("%d = %d + ... + %d\n", n, a, int(a + len - 1));
	}
	return 0;
}
