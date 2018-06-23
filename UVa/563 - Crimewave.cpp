#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 50;
int node[N][N], nodeE[N][N];
vector<int> G[5002];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
int qu[5002], vis[5002], vs, par[5002];
int g[5002][5002];

void addEdge(int u, int v) {
	if (g[u][v] == 0 && g[v][u] == 0) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	++g[u][v];
}

bool BFS(int src, int sink) {
	int s = 0, e = 0;
	qu[e++] = src;
	vis[src] = ++vs;
	while (s < e) {
		int v = qu[s++];
		for (size_t i = 0; i < G[v].size(); ++i) {
			int u = G[v][i];
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

int maxFlow(int src, int sink) {
	int flow = 0;
	while (BFS(src, sink)) {
		++flow;
		for (int u = sink; u != src; u = par[u]) {
			int v = par[u];
			++g[u][v];
			--g[v][u];
		}
	}
	return flow;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, k, id = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				node[i][j] = ++id;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				nodeE[i][j] = ++id;
		for (int i = 0; i <= id; ++i) {
			G[i].clear();
			for (int j = i; j <= id; ++j)
				g[i][j] = g[j][i] = 0;
		}
		for (int i = 0; i < k; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			addEdge(0, node[x][y]);
		}
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y) {
				addEdge(node[x][y], nodeE[x][y]);
				for (int i = 0; i < 4; ++i) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx >= 0 && ty >= 0 && tx < n && ty < m)
						addEdge(nodeE[x][y], node[tx][ty]);
				}
				if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
					addEdge(nodeE[x][y], id);
			}
		if (maxFlow(0, id) >= k)
			puts("possible");
		else
			puts("not possible");
	}
	return 0;
}
