#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, cost[120][15][15], dp[120][15];
char s[111];

int calc(int i, int j) {
	if (i == n - 1)
		return 0;
	int &res = dp[i][j];
	if (res != -1)
		return res;
	res = 2e9;
	for (int k = 0; k < m; ++k)
		res = min(res, calc(i + 1, k) + cost[i][j][k] + 2);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n - 1; ++i)
			for (int j = 0; j < m; ++j)
				for (int k = 0; k < m; ++k)
					scanf("%d", &cost[i][j][k]);
		memset(dp, -1, sizeof dp);
		int res = 2e9;
		for (int i = 0; i < m; ++i)
			res = min(res, calc(0, i));
		printf("%s\n%d\n", s, res);
	}
	return 0;
}
