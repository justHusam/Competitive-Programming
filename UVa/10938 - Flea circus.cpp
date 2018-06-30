#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e3;
int n, q, dep[N], par[N], dp[N][14];
vector<int> g[N];

void DFS(int v) {
	for (int i = 0; i < g[v].size(); ++i)
		if (g[v][i] != par[v]) {
			par[g[v][i]] = v;
			dep[g[v][i]] = dep[v] + 1;
			DFS(g[v][i]);
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

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			memset(dp[i], -1, sizeof dp[i]);
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dep[0] = 0;
		par[0] = -1;
		DFS(0);
		for (int i = 0; i < n; ++i)
			dp[i][0] = par[i];
		for (int j = 1; (1 << j) < n; ++j)
			for (int i = 0; i < n; ++i)
				if (dp[i][j - 1] != -1)
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
		scanf("%d", &q);
		while (q--) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			int lca = LCA(u, v);
			int len = dep[u] + dep[v] - (dep[lca] << 1);
			if (dep[v] < dep[u])
				swap(u, v);
			int need = dep[v] - (len >> 1);
			int log = 0;
			while ((1 << log) <= dep[v])
				++log;
			--log;
			for (int i = log; i >= 0;--i)
				if(dep[v] - (1 << i) >= need)
					v = dp[v][i];
			if (len & 1)
				printf("The fleas jump forever between %d and %d.\n", min(v, par[v]) + 1, max(v, par[v]) + 1);
			else
				printf("The fleas meet at %d.\n", v + 1);
			
		}
	}
	return 0;
}