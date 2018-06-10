#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, dp[N][2];
vector<int> g[N];

int calc(int v, int c, int p) {
	int &res = dp[v][c];
	if (res != -1)
		return res;
	res = c;
	for (size_t i = 0; i < g[v].size(); ++i) {
		if (g[v][i] == p)
			continue;
		int mn = calc(g[v][i], !c, v);
		if (c)
			mn = min(mn, calc(g[v][i], c, v));
		res += mn;
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", min(calc(0, 0, -1), calc(0, 1, -1)));
	}
	return 0;
}
