#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, v[8], dp[1 << 11][8][8], str, dr[] = { 4, 5, 6, 7, 0, 1, 2, 3 };
char g[12][12];

inline int calc(int mask, int col, int str) {
	if (mask == (1 << n) - 1) {
		if (col == str)
			return 0;
		return 2e9;
	}
	if (dp[mask][col][str] != -1)
		return dp[mask][col][str];
	int res = 2e9;
	for (int i = 0; i < n; ++i)
		if (((mask >> i) & 1) != 1)
			for (int j = 0; j < 8; ++j)
				if (g[i][j] - 'A' == col)
					res = min(res, calc(mask | (1 << i), g[i][dr[j]] - 'A', str) + v[g[i][dr[j]] - 'A']);
	return dp[mask][col][str] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n > 0) {
		for (int i = 0; i < 8; ++i)
			scanf("%d", v + i);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		memset(dp, -1, sizeof dp);
		int res = 2e9;
		for (int i = 0; i < 8; ++i) {
			str = g[0][i] - 'A';
			res = min(res, calc(0 | (1 << 0), g[0][dr[i]] - 'A', str) + v[g[0][dr[i]] - 'A']);
		}
		if (res == 2e9)
			puts("impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
