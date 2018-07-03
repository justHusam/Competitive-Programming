#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int n, m, x[N], y[N], dp[N][N];

int calc(int i, int j) {
	if (i == n || j == m)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = 1 + calc(i + 1, j + 1);
	int a = calc(i + 1, j);
	int b = calc(i, j + 1);
	return dp[i][j] = max(a, b);
}

int main(int argc, char **argv) {
	int caseN = 1;
	while (scanf("%d%d", &n, &m) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &y[i]);
		memset(dp, -1, sizeof dp);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", caseN++, calc(0, 0));
	}
	return 0;
}
