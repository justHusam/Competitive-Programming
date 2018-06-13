#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3;
vector<pair<int, int> > adj[N];
int g[N][N], par[N], vis[N], cost[N], vs;
pair<int, int> qu[N];

int Dijkstra(int str, int tar) {
	priority_queue<pair<int, int> > qu;
	qu.push(make_pair(2e9, str));
	++vs;
	cost[str] = 2e9;
	while (!qu.empty()) {
		pair<int, int> e = qu.top();
		qu.pop();
		if (e.second == tar)
			return e.first;
		if (vis[e.second] == vs)
			continue;
		vis[e.second] = vs;
		for (size_t i = 0; i < adj[e.second].size(); ++i) {
			int u = adj[e.second][i].first;
			int c = min(e.first, adj[e.second][i].second);
			if (vis[u] == vs || c <= cost[u])
				continue;
			cost[u] = c;
			qu.push(make_pair(c, u));
		}
	}
	return 0;
}

int BFS(int str, int tar) {
	int s = 0, e = 0;
	qu[e++] = make_pair(str, 2e9);
	vis[str] = ++vs;
	while (s < e) {
		pair<int, int>&fr = qu[s++];
		for (size_t i = 0; i < adj[fr.first].size(); ++i) {
			int u = adj[fr.first][i].first;
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
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int k, n, m, str, tar;
		scanf("%d%d%d%d%d", &k, &n, &m, &str, &tar);
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			cost[i] = 0;
			for (int j = i; j < n; ++j)
				g[i][j] = g[j][i] = 0;
		}
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			g[u][v] += c;
			adj[u].push_back(make_pair(v, c));
			adj[v].push_back(make_pair(u, c));
		}
		printf("%d %.3lf\n", k, maxFlow(str, tar) * 1.0 / Dijkstra(str, tar));
	}
	return 0;
}
