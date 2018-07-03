#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dp[205][22], m, c;
vector<vector<int> > g;

int calc(int rem, int at) {
	if (rem < 0)
		return -2;
	if (at == c)
		return m - rem;
	if (dp[rem][at] != -1)
		return dp[rem][at];
	int res = -2;
	for (size_t i = 0; i < g[at].size(); ++i)
		res = max(res, calc(rem - g[at][i], at + 1));
	return dp[rem][at] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &m, &c);
		g.clear();
		g.resize(c);
		for (int i = 0; i < c; ++i) {
			int n;
			scanf("%d", &n);
			g[i].resize(n);
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		}
		memset(dp, -1, sizeof dp);
		int res = calc(m, 0);
		if (res == -2)
			puts("no solution");
		else
			printf("%d\n", res);
	}
	return 0;
}
