#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dp[1005][11], x, g[1005][11];

int calc(int i, int j) {
	if (i == 0 && j == x / 100)
		return 0;
	if (i == -1 || i == 10 || j == x / 100)
		return 2e9;
	if (dp[j][i] != -1)
		return dp[j][i];
	int a = -g[j][i] + 60 + calc(i + 1, j + 1);
	int b = -g[j][i] + 30 + calc(i, j + 1);
	int c = -g[j][i] + 20 + calc(i - 1, j + 1);
	return dp[j][i] = min(a, min(b, c));
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &x);
		for (int i = 9; i >= 0; --i)
			for (int j = 0; j < x / 100; ++j)
				scanf("%d", &g[j][i]);
		memset(dp, -1, sizeof dp);
		printf("%d\n\n", calc(0, 0));
	}
	return 0;
}
