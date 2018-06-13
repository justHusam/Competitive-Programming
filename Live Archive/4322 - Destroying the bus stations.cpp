#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, c, f, nxt;
	edge(int u, int c, int f, int nxt) :
			u(u), c(c), f(f), nxt(nxt) {
	}
};

const int N = 100;
vector<edge> e;
int n, m, K, head[N], level[N], vis[N], qu[N], work[N], vs, can[50][50];

void addEdge(int u, int v, int c) {
	e.push_back(edge(v, c, 0, head[u]));
	head[u] = e.size() - 1;
	e.push_back(edge(u, 0, 0, head[v]));
	head[v] = e.size() - 1;
}

bool BFS(int src, int sink) {
	int l = 0, r = 0;
	qu[r++] = src;
	vis[src] = ++vs;
	level[src] = 0;
	while (l < r) {
		int v = qu[l++];
		for (int i = head[v]; i != -1; i = e[i].nxt) {
			int u = e[i].u;
			if (vis[u] == vs || e[i].f >= e[i].c)
				continue;
			vis[u] = vs;
			level[u] = level[v] + 1;
			qu[r++] = u;
		}
	}
	return vis[sink] == vs;
}

int DFS(int v, int sink, int f) {
	if (v == sink)
		return f;
	for (int &i = work[v]; i != -1; i = e[i].nxt)
		if (e[i].f < e[i].c && level[v] + 1 == level[e[i].u]) {
			int res = DFS(e[i].u, sink, min(f, e[i].c - e[i].f));
			if (res != -1) {
				e[i].f += res;
				e[i ^ 1].f -= res;
				return res;
			}
		}
	return -1;
}

int maxFlow(int src, int sink) {
	int flow = 0;
	while (BFS(src, sink)) {
		for (int i = 0; i < n * 2; ++i)
			work[i] = head[i];
		while (true) {
			int res = DFS(src, sink, 2e9);
			if (res == -1)
				break;
			flow += res;
		}
	}
	return flow;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &m, &K) && n + m + K != 0) {
		for (int i = 0; i < n * 2; ++i)
			head[i] = -1;
		e.clear();
		for (int i = 0; i < n; ++i) {
			addEdge(i, i + n, i ? 1 : 2e9);
			can[i][i] = 0;
			for (int j = i + 1; j < n; ++j)
				can[i][j] = can[j][i] = 1e9;
		}
		vector<pair<int, int> > E;
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			E.push_back(make_pair(u, v));
			can[u][v] = 1;
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					can[i][j] = min(can[i][j], can[i][k] + can[k][j]);
		for (size_t i = 0; i < E.size(); ++i) {
			int u = E[i].first, v = E[i].second;
			if (can[0][u] + can[v][n - 1] + 1 <= K)
				addEdge(u + n, v, 1);
		}
		printf("%d\n", maxFlow(0, n - 1));
	}
	return 0;
}
