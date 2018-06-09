#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000;
int n, m, par[N], dep[N], dp[N][11];
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
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		printf("Case %d:\n", cas++);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 0; i < n; ++i) {
			int x, u;
			scanf("%d", &x);
			for (int j = 0; j < x; ++j) {
				scanf("%d", &u);
				--u;
				g[i].push_back(u);
				g[u].push_back(i);
			}
		}
		par[0] = -1;
		dep[0] = 0;
		DFS(0);
		for (int i = 0; i < n; ++i)
			dp[i][0] = par[i];
		for (int j = 1; (1 << j) < n; ++j)
			for (int i = 0; i < n; ++i)
				if (dp[i][j - 1] != -1)
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
				else
					dp[i][j] = -1;
		int q;
		scanf("%d", &q);
		while (q-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			printf("%d\n", LCA(u, v) + 1);
		}
	}
	return 0;
}
