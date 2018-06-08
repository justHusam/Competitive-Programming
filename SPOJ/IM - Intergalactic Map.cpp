#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, c, f, nxt;
	edge(int u, int c, int f, int nxt) :
			u(u), c(c), f(f), nxt(nxt) {
	}
};

int n, m, vs;
vector<int> head, level, work, vis, qu;
vector<edge> e;

void addEdge(int u, int v, int c) {
	swap(u, v);
	e.push_back(edge(u, c, 0, head[v]));
	head[v] = e.size() - 1;
	e.push_back(edge(v, 0, 0, head[u]));
	head[u] = e.size() - 1;
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
			if (e[i].f >= e[i].c || vis[u] == vs)
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

bool maxFlow(int src, int sink) {
	int flow = 0;
	while (BFS(src, sink)) {
		for (int i = 0; i <= sink; ++i)
			work[i] = head[i];
		while (true) {
			int res = DFS(src, sink, 1e9);
			if (res == -1)
				break;
			flow += res;
		}
	}
	return flow == 2;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		int src = 1, sink = n * 2, N = n * 2 + 1;
		e.clear();
		head = vector<int>(N, -1);
		for (int i = 0; i < n; ++i)
			if (i != 1)
				addEdge(i, i + n, 1);
		addEdge(src, src + n, 2);
		addEdge(n, sink, 1);
		addEdge(2 + n, sink, 1);
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (u <= 0 || v <= 0 || u > n || v > n)
				continue;
			--u;
			--v;
			addEdge(u + n, v, 1);
			addEdge(v + n, u, 1);
		}
		level = vector<int>(N);
		work = vector<int>(N);
		vis = vector<int>(N);
		qu = vector<int>(N);
		if (maxFlow(src, sink))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
