#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 15;
int n, with, v[N], g[N][N];
short dp[1 << 14][101][15], vis[1 << 14][101][15], id;

int calc(bitset<14> msk, int w, int i) {
	if (w < 0)
		return -10000;
	if (vis[msk.to_ulong()][w][i] == id)
		return dp[msk.to_ulong()][w][i];
	vis[msk.to_ulong()][w][i] = id;
	int res = 0;
	for (int j = 1; j < n; ++j)
		if (!msk[j - 1]) {
			msk[j - 1] = 1;
			res = max(res, calc(msk, w - g[i][j] - v[j], j) + 1);
			msk[j - 1] = 0;
		}
	return dp[msk.to_ulong()][w][i] = res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &with);
		for (int i = 1; i < n; ++i)
			scanf("%d", v + i);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		++id;
		printf("Case %d: %d\n", k++, calc(0, with, 0));
	}
	return 0;
}
