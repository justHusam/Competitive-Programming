#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, src, tar, d, dp[100][200];
vector<int> g[100];

int calc(int v, int w) {
	if (w == d)
		return v == tar;
	if (v == tar)
		return 0;
	int &res = dp[v][w];
	if (res != -1)
		return res;
	res = 0;
	for (size_t i = 0; i < g[v].size() && !res; ++i)
		res = max(res, calc(g[v][i], w + 1));
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		scanf("%d%d%d", &src, &tar, &d);
		--src;
		--tar;
		memset(dp, -1, sizeof dp);
		int can = calc(src, 0);
		if (can != 0)
			puts("Yes, Teobaldo can travel.");
		else
			puts("No, Teobaldo can not travel.");
	}
	return 0;
}
