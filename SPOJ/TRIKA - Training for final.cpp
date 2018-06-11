#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, m, X, Y, g[25][25], dp[25][25];

inline int calc(int x, int y) {
	if (x == n - 1 && y == n - 1)
		return g[x][y];
	if (x >= n || y >= m)
		return 2e9;
	if (dp[x][y] != -1)
		return dp[x][y];
	int a = calc(x + 1, y) + g[x][y];
	int b = calc(x, y + 1) + g[x][y];
	return dp[x][y] = min(a, b);
}

int main(int argc, char **argv) {
	scanf("%d%d%d%d", &n, &m, &X, &Y);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &g[i][j]);
	--X;
	--Y;
	memset(dp, -1, sizeof dp);
	int res = g[X][Y] - min(calc(X + 1, Y), calc(X, Y + 1));
	if (res < 0)
		puts("N");
	else
		printf("Y %d\n", res);
	return 0;
}
