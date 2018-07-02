#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 20;
int n, m;
double dp[1 << N][N], g[N][N];

double calc(int mask, int at) {
	if (at == n)
		return 0;
	double &res = dp[mask][at];
	if (res != -1)
		return res;
	res = DBL_MAX;
	for (int i = 0; i < m; ++i)
		if (((mask >> i) & 1) == 0)
			res = min(res, calc(mask | (1 << i), at + 1) + g[at][i]);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%lf", &g[i][j]);
		for (int i = 0; i < (1 << m); ++i)
			for (int j = 0; j < n; ++j)
				dp[i][j] = -1;
		printf("%.2lf\n", calc(0, 0) / n + 1e-9);
	}
	return 0;
}
