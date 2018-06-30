#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 16;
int n, x[N], y[N];
double g[N][N], dp[1 << N];
char s[22];

double dist(int i, int j) {
	double a = x[i] - x[j];
	double b = y[i] - y[j];
	return sqrt(a * a + b * b);
}

double calc(int msk) {
	if (msk == (1 << (n * 2)) - 1)
		return 0;
	double &res = dp[msk];
	if (res == res)
		return res;
	res = 2e9;
	for (int i = 0; i < n * 2; ++i)
		if (((msk >> i) & 1) == 0)
			for (int j = 0; j < n * 2; ++j)
				if (i != j && ((msk >> j) & 1) == 0)
					res = min(res, calc(msk | (1 << i) | (1 << j)) + g[i][j]);
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n * 2; ++i)
			scanf("%s%d%d", s, &x[i], &y[i]);
		for (int i = 0; i < n * 2; ++i)
			for (int j = i + 1; j < n * 2; ++j)
				g[i][j] = g[j][i] = dist(i, j);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %.2lf\n", cas++, calc(0));
	}
	return 0;
}
