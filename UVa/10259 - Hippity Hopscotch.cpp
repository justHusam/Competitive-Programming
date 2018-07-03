#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, k, dp[100][100];
vector<vector<int> > g;

int calc(int x, int y) {
	if (dp[x][y] != -1)
		return dp[x][y];
	int res = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 1; j <= k; ++j) {
			int tx = x + dx[i] * j;
			int ty = y + dy[i] * j;
			if (tx < 0 || ty < 0 || tx >= n || ty >= n)
				break;
			if (g[tx][ty] > g[x][y])
				res = max(res, calc(tx, ty));
		}
	return dp[x][y] = res + g[x][y];
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &k);
		g.clear();
		g.resize(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
		if (T != 0)
			puts("");
	}
	return 0;
}
