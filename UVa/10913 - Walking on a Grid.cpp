#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int oo = 2e9;
int n, k, g[75][75], dp[75][75][6][2];

int calc(int x, int y, int w, bool f) {
	if (x < 0 || y < 0 || x >= n || y >= n || w > k)
		return -oo;
	if (x == n - 1 && y == n - 1) {
		if (g[x][y] < 0 && w == k)
			return -oo;
		return g[x][y];
	}
	int &res = dp[x][y][w][f];
	if (res != -1)
		return res;
	res = -oo;
	res = max(res, calc(x + 1, y, w + (g[x][y] < 0), false));
	res = max(res, calc(x + 1, y, w + (g[x][y] < 0), true));
	if (!f)
		res = max(res, calc(x, y - 1, w + (g[x][y] < 0), false));
	else
		res = max(res, calc(x, y + 1, w + (g[x][y] < 0), true));
	if (res != -oo)
		res += g[x][y];
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &n, &k) > 0 && n + k > 0) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		memset(dp, -1, sizeof dp);
		int res = calc(0, 0, 0, true);
		printf("Case %d: ", cas++);
		if (res == -oo)
			puts("impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
