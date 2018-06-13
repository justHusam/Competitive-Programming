#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int n, m, g[50][50], dp[50][50];

bool str(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= m)
			continue;
		if (g[tx][ty] > g[x][y])
			return false;
	}
	return true;
}

bool no(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= m)
			continue;
		if (g[tx][ty] < g[x][y])
			return false;
	}
	return true;
}

int calc(int x, int y) {
	if (dp[x][y] != -1)
		return dp[x][y];
	if (no(x, y))
		return dp[x][y] = 1;
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] >= g[x][y])
			continue;
		res += calc(tx, ty);
	}
	return dp[x][y] = res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (str(i, j))
					res += calc(i, j);
		printf("Case #%d: %d\n", k++, res);
	}
	return 0;
}
