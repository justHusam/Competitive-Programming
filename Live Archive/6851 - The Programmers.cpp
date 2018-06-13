#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, c, f, nxt;
	edge(int u, int c, int f, int nxt) :
			u(u), c(c), f(f), nxt(nxt) {
	}
};

const int N = 530;
int n, m, c, k, head[N], work[N], qu[N], vis[N], level[N], vs;
vector<int> can[500];
vector<edge> e;

inline void addEdge(int u, int v, int c) {
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
		for (int i = 0; i <= sink; ++i)
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
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d%d", &n, &m, &c, &k);
		for (int i = 0; i < n; ++i)
			can[i].clear();
		while (k-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			can[a].push_back(b);
		}
		int src = 0, sink = n + m + 1;
		for (int i = 0; i <= sink; ++i)
			head[i] = -1;
		e.clear();
		for (int i = 0; i < n; ++i) {
			addEdge(src, i + 1, 1);
			sort(can[i].begin(), can[i].end());
			can[i].resize(unique(can[i].begin(), can[i].end()) - can[i].begin());
			for (size_t j = 0; j < can[i].size(); ++j)
				addEdge(i + 1, can[i][j] + n + 1, 1);
		}
		for (int i = 0; i < m; ++i)
			addEdge(i + n + 1, sink, c);
		printf("%d\n", maxFlow(src, sink));
	}
	return 0;
}
