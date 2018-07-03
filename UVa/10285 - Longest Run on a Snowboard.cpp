#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int t, n, m, g[100][100], dp[100][100];
char s[1000];

int calc(int i, int j) {
	if (dp[i][j] != -1)
		return dp[i][j];
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		int tx = i + dx[i];
		int ty = j + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] >= g[i][j])
			continue;
		res = max(res, calc(tx, ty));
	}
	return dp[i][j] = res + 1;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%s%d%d", s, &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				res = max(res, calc(i, j));
		printf("%s: %d\n", s, res);
	}
	return 0;
}
