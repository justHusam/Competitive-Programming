#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e6 + 7;
int n, m, k, dp[20][20][501][16];

inline void add(int &res, int x) {
	res += x;
	if (res >= M)
		res -= M;
}

int calc(int x, int y, int k, int mask) {
	if (k == 0)
		return mask == 15;
	if (x == n)
		return 0;
	int &res = dp[x][y][k][mask];
	if (res != -1)
		return res;
	res = 0;
	if (y + 1 == m)
		add(res, calc(x + 1, 0, k, mask));
	else
		add(res, calc(x, y + 1, k, mask));
	int nmask = mask;
	if (x == 0)
		nmask |= 1;
	if (x == n - 1)
		nmask |= 8;
	if (y == 0)
		nmask |= 2;
	if (y == m - 1)
		nmask |= 4;
	if (y + 1 == m)
		add(res, calc(x + 1, 0, k - 1, nmask));
	else
		add(res, calc(x, y + 1, k - 1, nmask));
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int _k = 1; _k <= k; ++_k)
					memset(dp[i][j][_k], -1, sizeof dp[i][j][_k]);
		printf("Case %d: %d\n", cas++, calc(0, 0, k, 0));
	}
	return 0;
}
