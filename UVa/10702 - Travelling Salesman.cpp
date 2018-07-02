#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 100;
int n, src, e, all, dp[1001][N], g[N][N];
bool E[N];

int calc(int w, int at) {
	if (w == 0)
		return -2e9 * E[at];
	if (dp[w][at] == -1) {
		dp[w][at] = 0;
		for (int i = 0; i < n; ++i)
			dp[w][at] = max(dp[w][at], calc(w - 1, i) + g[at][i]);
	}
	return dp[w][at];
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d%d", &n, &src, &e, &all) > 0 && n != 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
			E[i] = true;
		}
		while (e-- != 0) {
			int x;
			scanf("%d", &x);
			E[x - 1] = false;
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(all, src - 1));
	}
	return 0;
}
