#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int l, s, dp[352][27][27], k;

int calc(int r, int c, int i) {
	if (c == l)
		return r == 0;
	if (r < 0)
		return 0;
	if (dp[r][c][i] != -1)
		return dp[r][c][i];
	int res = 0;
	for (int j = i + 1; j <= 26; ++j)
		res += calc(r - j, c + 1, j);
	return dp[r][c][i] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &l, &s) > 0 && l != 0) {
		printf("Case %d: ", ++k);
		if (l > 26 || s > 351) {
			puts("0");
			continue;
		}
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 1; i <= 26; ++i)
			res += calc(s - i, 1, i);
		printf("%d\n", res);
	}
	return 0;
}
