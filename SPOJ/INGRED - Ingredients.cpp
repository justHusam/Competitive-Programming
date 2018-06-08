#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, s, g[N][N], at[8], dp[N][N][1 << 8], all;

int calc(int u, int v, int mask) {
	if (mask == all)
		return 0;
	int &res = dp[u][v][mask];
	if (res != -1)
		return res;
	res = 2e9;
	for (int i = 0; i < s; ++i)
		if (((mask >> i) & 1) == 0) {
			res = min(res, calc(at[i], v, mask | (1 << i)) + g[u][at[i]]);
			res = min(res, calc(u, at[i], mask | (1 << i)) + g[v][at[i]]);
		}
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);
	for (int i = 0; i < n; ++i)
		g[i][i] = 0;
	while (m-- != 0) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		g[u][v] = min(g[u][v], c);
		g[v][u] = min(g[v][u], c);
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	scanf("%d", &s);
	for (int i = 0; i < s; ++i)
		scanf("%d", &at[i]);
	int u, v;
	scanf("%d%d", &u, &v);
	memset(dp, -1, sizeof dp);
	all = (1 << s) - 1;
	printf("%d\n", calc(u, v, 0));
	return 0;
}
