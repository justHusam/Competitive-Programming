#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, t, p;
ll dp[71][71];

ll calc(int r, int c) {
	if (c == n - 1)
		return r >= p;
	if (r < p)
		return 0;
	if (dp[r][c] != -1)
		return dp[r][c];
	int res = 0;
	for (int i = p;; ++i) {
		if (r - i < 0)
			break;
		res += calc(r - i, c + 1);
	}
	return dp[r][c] = res;
}

int main(int argc, char **argv) {
	int k;
	scanf("%d", &k);
	while (k-- != 0) {
		scanf("%d%d%d", &n, &t, &p);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", calc(t, 0));
	}
	return 0;
}
