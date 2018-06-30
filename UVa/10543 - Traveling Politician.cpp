#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k, dp[50][17];
vector<int> g[50];

int calc(int v, int w) {
	if (v == n - 1 && w + 1 >= k)
		return 1;
	if (w == 20)
		return 2e9;
	int &res = dp[v][w];
	if (res != -1)
		return res;
	res = 2e9;
	for (size_t i = 0; i < g[v].size(); ++i)
		res = min(res, calc(g[v][i], min(k, w + 1)) + 1);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &m, &k) > 0 && n + m + k > 0) {
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
		}
		memset(dp, -1, sizeof dp);
		int res = calc(0, 0);
		if (res == 2e9)
			puts("LOSER");
		else
			printf("%d\n", res);
	}
	return 0;
}
