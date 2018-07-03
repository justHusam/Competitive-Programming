#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, dp[N][31], p[N], w[N];

int calc(int i, int r) {
	if (r < 0)
		return -(2e9);
	if (i == n)
		return 0;
	if (dp[i][r] != -1)
		return dp[i][r];
	int a = calc(i + 1, r - w[i]) + p[i];
	int b = calc(i + 1, r);
	return dp[i][r] = max(a, b);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &p[i], &w[i]);
		int res = 0, g;
		scanf("%d", &g);
		memset(dp, -1, sizeof dp);
		while (g-- != 0) {
			int r;
			scanf("%d", &r);
			res += calc(0, r);
		}
		printf("%d\n", res);
	}
	return 0;
}
