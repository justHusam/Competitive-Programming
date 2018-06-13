#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, add[N][50], g[N][N], dp[N][50];

int calc(int at, int w) {
	if (w + 1 == m)
		return 0;
	int &res = dp[at][w];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 0; i < n; ++i)
		res = max(res, calc(i, w + 1) + add[i][w + 1] - g[at][i]);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &add[i][j]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < n; ++i)
			res = max(res, calc(i, 0) + add[i][0]);
		printf("%d\n", res);
	}
	return 0;
}
