#include <bits/stdc++.h>
using namespace std;

int n, dp[100002][4], g[100002][4];

int calc(int i, int j) {
	if (j < 0 || j > 2)
		return INT_MAX;
	if (dp[i][j] != INT_MAX)
		return dp[i][j];
	if (i == n - 1) {
		if (j == 1)
			return g[i][j];
		if (j == 2)
			return INT_MAX;
		if (j == 0)
			return g[i][0] + g[i][1];
	}
	int a = calc(i, j + 1);
	int b = calc(i + 1, j);
	int c = calc(i + 1, j + 1);
	int d = calc(i + 1, j - 1);
	return dp[i][j] = g[i][j] + min(min(a, b), min(c, d));
}

int main(int argc, char **argv) {
	int k = 1;
	while (scanf("%d", &n) && n) {
		for (int a = 0; a < 3; ++a)
			for (int b = 0; b < 3; ++b) {
				scanf("%d", &g[a][b]);
			}
		for (int i = 0; i < 100002; ++i)
			fill(dp[i], dp[i] + 4, INT_MAX);
		printf("%d. %d\n", k++, calc(0, 1));
	}
	return 0;
}
