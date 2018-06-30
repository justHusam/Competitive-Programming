#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, m, c;
	while (scanf("%d%d%d", &n, &m, &c) > 0 && n != 0) {
		n -= 7;
		m -= 7;
		int r1 = (n + 1) >> 1, r2 = n >> 1, c1 = (m + 1) >> 1, c2 = m >> 1;
		if (c == 0)
			swap(r1, r2);
		printf("%lld\n", (ll) r1 * c1 + (ll) r2 * c2);
	}
	return 0;
}
