#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 202;
vector<int> adj[N];
int g[N][N], vis[N], par[N], vs;
pair<int, int> qu[N];
bool edge[N][N];

void addEdge(int u, int v, int c) {
	g[u][v] += c;
	if (!edge[u][v]) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	edge[u][v] = edge[v][u] = true;
}

int BFS(int str, int tar) {
	int s = 0, e = 0;
	qu[e++] = make_pair(str, 2e9);
	vis[str] = ++vs;
	while (s < e) {
		pair<int, int>&fr = qu[s++];
		for (size_t i = 0; i < adj[fr.first].size(); ++i) {
			int u = adj[fr.first][i];
			int c = min(fr.second, g[fr.first][u]);
			if (vis[u] == vs || !c)
				continue;
			vis[u] = vs;
			par[u] = fr.first;
			qu[e++] = make_pair(u, c);
			if (u == tar)
				return c;
		}
	}
	return -1;
}

int maxFlow(int str, int tar) {
	int flow = 0;
	while (true) {
		int res = BFS(str, tar);
		if (res == -1)
			break;
		flow += res;
		for (int u = tar; u != str; u = par[u]) {
			int v = par[u];
			g[u][v] += res;
			g[v][u] -= res;
		}
	}
	return flow;
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n * 2 + 2; ++i) {
			adj[i].clear();
			for (int j = i; j < n * 2 + 2; ++j)
				g[i][j] = g[j][i] = 0, edge[i][j] = edge[j][i] = false;
		}
		for (int i = 0, c; i < n; ++i) {
			scanf("%d", &c);
			addEdge(i, i + n, c);
		}
		int m;
		scanf("%d", &m);
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			addEdge(u + n, v, c);
		}
		int b, d;
		scanf("%d%d", &b, &d);
		while (b-- != 0) {
			int u;
			scanf("%d", &u);
			--u;
			addEdge(n * 2, u, 1e9);
		}
		while (d-- != 0) {
			int u;
			scanf("%d", &u);
			--u;
			addEdge(u + n, n * 2 + 1, 1e9);
		}
		printf("%d\n", maxFlow(n * 2, n * 2 + 1));
	}
	return 0;
}
