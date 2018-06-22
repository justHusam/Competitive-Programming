#include <bits/stdc++.h>
using namespace std;

int dp[105][105], g[105][105], n;

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &g[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dp[i][j] = g[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
	int res = -2e9;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = i + 1; k <= n; ++k)
				for (int l = j + 1; l <= n; ++l)
					res = max(res, dp[k][l] - dp[i][l] - dp[k][j] + dp[i][j]);
	printf("%d\n", res);
	return 0;
}
