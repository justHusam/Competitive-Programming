#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct edge {
	int u, c, f, nxt;
	edge() {
	}
	edge(int u, int c, int f, int nxt) :
			u(u), c(c), f(f), nxt(nxt) {
	}
};

const int N = 50;
edge e[1000];
int n, m, head[N], level[N], work[N], qu[N], vis[N], vs, idx;

void addEdge(int u, int v, int c) {
	e[idx] = edge(u, c, 0, head[v]);
	head[v] = idx++;
	e[idx] = edge(v, c, 0, head[u]);
	head[u] = idx++;
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
		for (int i = 0; i < n; ++i)
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

void BFS(int src) {
	int l = 0, r = 0;
	qu[r++] = src;
	vis[src] = ++vs;
	while (l < r) {
		int v = qu[l++];
		for (int i = head[v]; i != -1; i = e[i].nxt) {
			int u = e[i].u;
			if (vis[u] == vs || e[i].f >= e[i].c)
				continue;
			vis[u] = vs;
			qu[r++] = u;
		}
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m != 0) {
		for (int i = 0; i < n; ++i)
			head[i] = -1;
		idx = 0;
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			addEdge(u, v, c);
		}
		maxFlow(0, 1);
		++vs;
		BFS(0);
		for (int i = 0; i < idx; ++i)
			if (vis[e[i].u] == vs && vis[e[i ^ 1].u] != vs)
				printf("%d %d\n", e[i].u + 1, e[i ^ 1].u + 1);
		puts("");
	}
	return 0;
}
