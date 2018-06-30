#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1802;
int n, m, can, hs[31][31], g[N][N], vis[N], par[N], qu[N], vs;
char s[32][32];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
vector<int> adj[N];

inline int N1(int x, int y) {
	return hs[x][y] + n * m;
}

void addEdge(int u, int v, int c) {
	if (!g[u][v] && !g[v][u]) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	g[u][v] += c;
}

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
	while (scanf("%d%d%d", &n, &m, &can) > 0) {
		int id = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf(" %c", &s[i][j]);
				hs[i][j] = ++id;
			}
		int src = 0, sink = (id * 2) + 1;
		for (int i = 0; i <= sink; ++i) {
			adj[i].clear();
			for (int j = i; j <= sink; ++j)
				g[i][j] = g[j][i] = 0;
		}
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y) {
				if (s[x][y] == '~')
					continue;
				if (s[x][y] == '*') {
					addEdge(src, hs[x][y], 1e9);
					addEdge(hs[x][y], N1(x, y), 1);
				}
				if (s[x][y] == '.')
					addEdge(hs[x][y], N1(x, y), 1);
				if (s[x][y] == '@')
					addEdge(hs[x][y], N1(x, y), 1e9);
				if (s[x][y] == '#') {
					addEdge(hs[x][y], N1(x, y), 1e9);
					addEdge(N1(x, y), sink, can);
				}
				for (int i = 0; i < 4; ++i) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx >= 0 && ty >= 0 && tx < n && ty < m && g[tx][ty] != '~' && g[tx][ty] != '*') {
						addEdge(N1(x, y), hs[tx][ty], 1e9);
					}
				}
			}
		printf("%d\n", maxFlow(src, sink));
	}
	return 0;
}
