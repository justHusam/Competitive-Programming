#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 100;
vector<int> adj[N];
int n, m, g[N][N], cap[N][N], vis[N], par[N], qu[N], vs;
char z[1111];

void addEdge(int u, int v) {
	if (!cap[u][v] && !cap[v][u]) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	++cap[u][v];
}

void DFS(int v) {
	vis[v] = vs;
	for (size_t i = 0; i < adj[v].size(); ++i)
		if (vis[adj[v][i]] != vs)
			DFS(adj[v][i]);
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
	for (int i = 0; i < n * 2; ++i)
		for (int j = 0; j < n * 2; ++j)
			g[i][j] = cap[i][j];
	g[src][src + n] = 1e9;
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
	while (scanf("%d%d", &n, &m) > 0) {
		for (int i = 0; i < n * 2; ++i) {
			adj[i].clear();
			for (int j = i; j < n * 2; ++j)
				g[i][j] = g[j][i] = cap[i][j] = cap[j][i] = 0;
		}
		for (int i = 0; i < n; ++i)
			addEdge(i, i + n);
		while (m > 0) {
			scanf("%s", z);
			string s = z;
			size_t x = 0;
			while (x < s.size()) {
				int i = s.find('(', x) + 1;
				int j = s.find(',', x);
				int k = s.find(')', x);
				int u = 0, v = 0;
				while (i < j)
					u = u * 10 + (s[i++] - '0');
				++j;
				while (j < k)
					v = v * 10 + (s[j++] - '0');
				addEdge(u + n, v);
				addEdge(v + n, u);
				--m;
				x = k + 1;
			}
		}
		if (n < 2) {
			printf("%d\n", n);
			continue;
		}
		++vs;
		DFS(0);
		int can = 0;
		for (int i = 0; i < n; ++i)
			can += vis[i] == vs;
		if (can != n) {
			puts("0");
			continue;
		}
		set<int> res;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				res.insert(maxFlow(i, j));
		if (res.size() == 1 && *res.begin() == n - 1)
			printf("%d\n", n);
		else
			printf("%d\n", *res.begin());
	}
	return 0;
}
