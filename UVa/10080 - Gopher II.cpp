#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 202;
vector<int> adj[N];
int g[N][N], vis[N], par[N], qu[N], vs;
pair<double, double> a[100], b[100];

double dist(int i, int j) {
	double x = a[i].first - b[j].first;
	double y = a[i].second - b[j].second;
	return sqrt(x * x + y * y);
}

void addEdge(int u, int v) {
	g[u][v] = 1;
	adj[u].push_back(v);
	adj[v].push_back(u);
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
	int n, m, s, v;
	while (scanf("%d%d%d%d", &n, &m, &s, &v) > 0) {
		int src = 0, sink = n + m + 1;
		for (int i = 0; i <= sink; ++i) {
			adj[i].clear();
			for (int j = i; j <= sink; ++j)
				g[i][j] = g[j][i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &a[i].first, &a[i].second);
			addEdge(src, i + 1);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%lf%lf", &b[i].first, &b[i].second);
			addEdge(i + n + 1, sink);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				double t = dist(i, j) / v;
				if (t <= s)
					addEdge(i + 1, j + n + 1);
			}
		printf("%d\n", n - maxFlow(src, sink));
	}
	return 0;
}
