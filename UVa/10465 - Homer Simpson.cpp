#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e4 + 1, oo = 2e9;
int n, m, t, dp[N], tar;

int calc(int w) {
	if (w == 0)
		return 0;
	if (w - n < 0 && w - m < 0)
		return w;
	if (dp[w] != -1)
		return dp[w];
	int res = w;
	if (w - n >= 0)
		res = min(res, calc(w - n));
	if (w - m >= 0)
		res = min(res, calc(w - m));
	return dp[w] = res;
}

int path(int w) {
	if (w == 0)
		return 0;
	if (w < 0)
		return -oo;
	if (dp[w] != -1)
		return dp[w];
	int res = -oo;
	res = max(res, path(w - n) + 1);
	res = max(res, path(w - m) + 1);
	return dp[w] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &m, &t) > 0) {
		memset(dp, -1, sizeof dp);
		int res = calc(t);
		tar = t - res;
		memset(dp, -1, sizeof dp);
		printf("%d", path(tar));
		if (res != 0)
			printf(" %d", res);
		puts("");
	}
	return 0;
}
