#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, v[10][10], cost[10][30][10], dp[10][1000];

int calc(int i, int w) {
	if (w == k - 1) {
		if (i != n - 1 && cost[i][w % v[i][n - 1]][n - 1])
			return cost[i][w % v[i][n - 1]][n - 1];
		return 2e9;
	}
	int &res = dp[i][w];
	if (res != -1)
		return res;
	res = 2e9;
	for (int j = 0; j < n; ++j)
		if (i != j)
			if (cost[i][w % v[i][j]][j])
				res = min(res, calc(j, w + 1) + cost[i][w % v[i][j]][j]);
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &n, &k) && (n != 0 || k != 0)) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				scanf("%d", &v[i][j]);
				for (int k = 0; k < v[i][j]; ++k)
					scanf("%d", &cost[i][k][j]);
			}
		memset(dp, -1, sizeof dp);
		int res = calc(0, 0);
		printf("Scenario #%d\n", cas++);
		if (res == 2e9)
			puts("No flight possible.");
		else
			printf("The best flight costs %d.\n", res);
		puts("");
	}
	return 0;
}
