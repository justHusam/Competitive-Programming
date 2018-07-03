#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int oo = 1e9;
int n, m, dp[11][101], g[11][101];

int calc(int c, int h) {
	if (h < 0)
		return -oo;
	if (c == n)
		return 0;
	if (dp[c][h] != -1)
		return dp[c][h];
	int res = -oo;
	for (int i = 1; i <= m; ++i)
		if (g[c][i - 1] >= 5) {
			int rec = calc(c + 1, h - i);
			if (rec != -oo)
				res = max(res, rec + g[c][i - 1]);
		}
	return dp[c][h] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		memset(dp, -1, sizeof dp);
		int res = calc(0, m);
		if (res == -oo)
			puts("Peter, you shouldn'T have played billiard that much.");
		else
			printf("Maximal possible average mark - %.2lf.\n", res / double(n) + 1e-9);
	}
	return 0;
}
