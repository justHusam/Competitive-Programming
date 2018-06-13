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

const int N = 100;
int n, m, cap[N][N], head[N], level[N], work[N], qu[N], vis[N], vs, idx;
edge e[2000];
char s[1000];

void addEdge(int u, int v, int c) {
	e[idx] = edge(u, c, 0, head[v]);
	head[v] = idx++;
	e[idx] = edge(v, c, 0, head[u]);
	head[u] = idx++;
}

int checkDFS(int v) {
	vis[v] = vs;
	int res = 1;
	for (int i = head[v]; i != -1; i = e[i].nxt)
		if (vis[e[i].u] != vs)
			res += checkDFS(e[i].u);
	return res;
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
	for (int i = 0; i < idx; ++i)
		e[i].f = 0;
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

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		for (int i = 0; i < n; ++i) {
			head[i] = -1;
			for (int j = i; j < n; ++j)
				cap[i][j] = cap[j][i] = 0;
		}
		idx = 0;
		while (m != 0) {
			scanf("%s", s);
			string z = s;
			size_t x = 0;
			while (x < z.size()) {
				int i = z.find('(', x) + 1;
				int j = z.find(',', x);
				int k = z.find(')', x);
				int u = 0, v = 0;
				while (i < j)
					u = u * 10 + (s[i++] - '0');
				++j;
				while (j < k)
					v = v * 10 + (s[j++] - '0');
				++cap[u][v];
				++cap[v][u];
				x = k + 1;
				--m;
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (cap[i][j])
					addEdge(i, j, cap[i][j]);
		++vs;
		if (n < 2 || checkDFS(0) != n) {
			puts("0");
			continue;
		}
		int res = 2e9;
		for (int i = 1; i < n; ++i)
			res = min(res, maxFlow(0, i));
		printf("%d\n", res);
	}
	return 0;
}
