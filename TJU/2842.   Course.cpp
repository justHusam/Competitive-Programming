#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 102;
vector<int> adj[N], can[50];
int n, m, k, g[N][N], par[N], vis[N], vs, qu[N];

bool BFS(int src, int sink) {
	int s = 0, e = 0;
	qu[e++] = src;
	vis[src] = ++vs;
	while (s < e) {
		int v = qu[s++];
		for (size_t i = 0; i < adj[v].size(); ++i) {
			int u = adj[v][i];
			if (vis[u] == vs || !g[v][u])
				continue;
			vis[u] = vs;
			par[u] = v;
			qu[e++] = u;
			if (u == sink)
				return true;
		}
	}
	return false;
}

void maxFlow(int src, int sink) {
	while (BFS(src, sink)) {
		for (int u = sink; u != src; u = par[u]) {
			int v = par[u];
			++g[u][v];
			--g[v][u];
		}
	}
}

int calc(int src, int sink, int can) {
	for (int i = 0; i <= sink; ++i)
		for (int j = i; j <= sink; ++j)
			g[i][j] = g[j][i] = 0;
	for (int i = 1; i <= n; ++i) {
		g[src][i] = can;
		for (size_t j = 1; j < adj[i].size(); ++j)
			++g[i][adj[i][j]];
	}
	for (int i = 1; i <= m; ++i)
		g[i + n][sink] = k;
	maxFlow(src, sink);
	for (int i = 1; i <= n; ++i)
		if (g[src][i])
			return false;
	return true;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &m, &k) && n + m + k != 0) {
		for (int i = 0; i <= n + m + 1; ++i)
			adj[i].clear();
		int mn = 2e9;
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			mn = min(mn, x);
			adj[0].push_back(i);
			adj[i].push_back(0);
			while (x--) {
				int u;
				scanf("%d", &u);
				adj[i].push_back(u + n);
				adj[u + n].push_back(i);
			}
		}
		for (int i = 1; i <= m; ++i)
			adj[i + n].push_back(n + m + 1);
		int s = 1, e = mn, src = 0, sink = n + m + 1, res = 0;
		while (s <= e) {
			int m = (s + e) / 2;
			if (calc(src, sink, m))
				s = m + 1, res = m;
			else
				e = m - 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
