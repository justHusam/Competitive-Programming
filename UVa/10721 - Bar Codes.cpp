#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, k, m;
ll dp[51][51];

inline ll calc(int x, int y) {
	if (x > n)
		return 0;
	if (y == k)
		return x == n;
	if (dp[x][y] != -1)
		return dp[x][y];
	ll res = 0;
	for (int i = 1; i <= m; ++i)
		res += calc(x + i, y + 1);
	return dp[x][y] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &k, &m) > 0) {
		memset(dp, -1, sizeof dp);
		printf("%lld\n", calc(0, 0));
	}
	return 0;
}
