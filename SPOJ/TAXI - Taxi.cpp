#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 602;
int p, t, s, c, g[N][N], vis[N], par[N], qu[N], vs;
pair<int, int> a[400], b[200];
vector<int> adj[N];

int dist(int i, int j) {
	return abs(b[i].first - a[j].first) + abs(b[i].second - a[j].second);
}

void addEdge(int u, int v, int c) {
	g[u][v] += c;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int BFS(int str, int tar) {
	int s = 0, e = 0;
	qu[e++] = str;
	vis[str] = ++vs;
	while (s < e) {
		int v = qu[s++];
		for (size_t i = 0; i < adj[v].size(); ++i) {
			int u = adj[v][i];
			if (vis[u] == vs || !g[v][u])
				continue;
			vis[u] = vs;
			par[u] = v;
			qu[e++] = u;
			if (u == tar)
				return true;
		}
	}
	return false;
}

int maxFlow(int str, int tar) {
	int flow = 0;
	while (BFS(str, tar)) {
		++flow;
		for (int u = tar; u != str; u = par[u]) {
			int v = par[u];
			++g[u][v];
			--g[v][u];
		}
	}
	return flow;
}

int main(int argc, char **argv) {
	int k;
	scanf("%d", &k);
	while (k-- != 0) {
		scanf("%d%d%d%d", &p, &t, &s, &c);
		int n = p + t + 1;
		for (int i = 0; i <= n; ++i) {
			adj[i].clear();
			for (int j = i; j <= n; ++j)
				g[i][j] = g[j][i] = 0;
		}
		for (int i = 0; i < p; ++i) {
			scanf("%d%d", &a[i].first, &a[i].second);
			addEdge(t + i + 1, t + p + 1, 1);
		}
		for (int i = 0; i < t; ++i) {
			scanf("%d%d", &b[i].first, &b[i].second);
			addEdge(0, i + 1, 1);
		}
		for (int i = 0; i < t; ++i)
			for (int j = 0; j < p; ++j) {
				double need = (dist(i, j) * 200.0) / s;
				if (need <= c)
					addEdge(i + 1, t + j + 1, 1);
			}
		printf("%d\n", maxFlow(0, t + p + 1));
	}
	return 0;
}
