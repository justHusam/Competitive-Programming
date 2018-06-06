#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, g[N][N], v[N][N], dp[N][N];

int calc(int u, int d) {
	if (d == m)
		return 0;
	int &res = dp[u][d];
	if (res != -1)
		return res;
	res = -2e9;
	for (int i = 0; i < n; ++i)
		res = max(res, calc(i, d + 1) - g[u][i] + v[i][d]);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		for (int j = 0; j < m; ++j)
			for (int i = 0; i < n; ++i)
				scanf("%d", &v[i][j]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
