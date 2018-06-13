#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 101;
int n, dp[N][N], c[N], r[N], p[N];

int calc(int i, int j) {
	if (i == n)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int res = calc(i + 1, i + 1) + (c[i] - c[j - 1] + 10) * p[i];
	if (i != n - 1)
		res = min(res, calc(i + 1, j));
	return dp[i][j] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		++n;
		for (int i = 1; i < n; ++i)
			scanf("%d%d", r + i, p + i);
		c[0] = 0;
		for (int i = 1; i < n; ++i)
			c[i] = r[i] + c[i - 1];
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
