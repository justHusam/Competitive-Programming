#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
int n, par[N], dep[N], dp[N][15], cost[N];
vector<pair<int, int> > g[N];

void DFS(int v) {
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i].first;
		if (u == par[v])
			continue;
		par[u] = v;
		dep[u] = dep[v] + 1;
		cost[u] = cost[v] + g[v][i].second;
		DFS(u);
	}
}

int LCA(int u, int v) {
	if (dep[v] < dep[u])
		swap(u, v);
	int log = 0;
	while ((1 << log) <= dep[v])
		++log;
	--log;
	for (int i = log; i >= 0; --i)
		if (dep[v] - (1 << i) >= dep[u])
			v = dp[v][i];
	if (v == u)
		return u;
	for (int i = log; i >= 0; --i)
		if (dp[u][i] != -1 && dp[v][i] != -1 && dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	return par[u];
}

int calc(int v, int k) {
	int log = 0;
	while ((1 << log) <= dep[v])
		++log;
	--log;
	k = dep[v] - k;
	for (int i = log; i >= 0; --i)
		if (dep[v] - (1 << i) >= k)
			v = dp[v][i];
	return v;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			cost[i] = 0;
			g[i].clear();
			memset(dp[i], -1, sizeof dp[i]);
		}
		for (int i = 1; i < n; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u, --v;
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}
		par[0] = -1;
		cost[0] = dep[0] = 0;
		DFS(0);
		for (int i = 0; i < n; ++i)
			dp[i][0] = par[i];
		for (int j = 1; (1 << j) < n; ++j)
			for (int i = 0; i < n; ++i)
				if (dp[i][j - 1] != -1)
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
		char z[10];
		while (scanf("%s", z) && z[1] != 'O') {
			int u, v, k;
			if (z[0] == 'D') {
				scanf("%d%d", &u, &v);
				--u, --v;
				int lca = LCA(u, v);
				printf("%d\n", cost[u] + cost[v] - (cost[lca] << 1));
			} else {
				scanf("%d%d%d", &u, &v, &k);
				--u, --v, --k;
				int lca = LCA(u, v), sol;
				if (u != lca && dep[u] - k >= dep[lca])
					sol = calc(u, k);
				else {
					k -= dep[u] - dep[lca];
					sol = calc(v, dep[v] - dep[lca] - k);
				}
				printf("%d\n", sol + 1);
			}
		}
		puts("");
	}
	return 0;
}
