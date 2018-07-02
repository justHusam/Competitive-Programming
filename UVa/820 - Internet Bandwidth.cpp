#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 100;
int g[N][N], vis[N], n, m, src, sink, par[N];
pair<int, int> qu[N];
vector<int> G[N];

int BFS() {
	static int id = 0;
	int s = 0, e = 0;
	qu[e++] = make_pair(src, 2e9);
	vis[src] = ++id;
	while (s < e) {
		pair<int, int> fr = qu[s++];
		for (int a = 0; a < G[fr.first].size(); ++a) {
			int u = G[fr.first][a];
			int c = min(fr.second, g[fr.first][u]);
			if (vis[u] == id || !c)
				continue;
			vis[u] = id;
			par[u] = fr.first;
			qu[e++] = make_pair(u, c);
			if (u == sink)
				return c;
		}
	}
	return -1;
}

int maxFlow() {
	int flow = 0;
	while (true) {
		int res = BFS();
		if (res == -1)
			break;
		flow += res;
		for (int u = sink; u != src; u = par[u]) {
			int v = par[u];
			g[u][v] += res;
			g[v][u] -= res;
		}
	}
	return flow;
}

int main(int argc, char **argv) {
	int k = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		scanf("%d%d%d", &src, &sink, &m);
		--src;
		--sink;
		for (int i = 0; i < n; ++i) {
			G[i].clear();
			for (int j = i; j < n; ++j)
				g[i][j] = g[j][i] = 0;
		}
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			g[u][v] += c;
			g[v][u] += c;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", k++, maxFlow());
	}
	return 0;
}
