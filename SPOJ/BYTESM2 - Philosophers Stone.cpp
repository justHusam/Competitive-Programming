#include <bits/stdc++.h>
using namespace std;

int t, h, w;
int dp[101][101], g[101][101];

int calc(int i, int j) {
	if (j < 0 || j >= w)
		return -1;
	if (i == h - 1)
		return dp[i][j] = g[i][j];
	if (dp[i][j] != -1)
		return dp[i][j];
	int A = calc(i + 1, j + 1);
	int B = calc(i + 1, j);
	int C = calc(i + 1, j - 1);
	return dp[i][j] = g[i][j] + max(A, max(B, C));;
}

int main(int argc, char **argv) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				scanf("%d", &g[i][j]);
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < w; ++i)
			res = max(res, calc(0, i));
		printf("%d\n", res);
	}
	return 0;
}
