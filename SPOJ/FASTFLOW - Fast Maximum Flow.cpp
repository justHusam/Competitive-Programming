#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct edge {
	int v, c, f, nxt;
	edge() {
	}
	edge(int v, int c, int f, int nxt) :
			v(v), c(c), f(f), nxt(nxt) {
	}
};

const int N = 5e3, M = 3e4;
int n, m, head[N], level[N], work[N], qu[N], str, tar, idx;
edge e[M * 2];

void addEdge(int u, int v, int c, int rc = 0) {
	e[idx] = edge(v, c, 0, head[u]);
	head[u] = idx++;
	e[idx] = edge(u, rc, 0, head[v]);
	head[v] = idx++;
}

bool BFS() {
	for (int i = 0; i < n; ++i)
		level[i] = -1;
	int l = 0, r = 0;
	qu[r++] = str;
	level[str] = 0;
	while (l < r) {
		for (int v = qu[l++], i = head[v]; i != -1; i = e[i].nxt) {
			if (e[i].f < e[i].c && level[e[i].v] == -1) {
				level[e[i].v] = level[v] + 1;
				qu[r++] = e[i].v;
			}
		}
	}
	return level[tar] != -1;
}

int DFS(int v, int f) {
	if (v == tar)
		return f;
	for (int &i = work[v]; i != -1; i = e[i].nxt)
		if (e[i].f < e[i].c && level[v] + 1 == level[e[i].v]) {
			int mn = DFS(e[i].v, min(f, e[i].c - e[i].f));
			if (mn) {
				e[i].f += mn;
				e[i ^ 1].f -= mn;
				return mn;
			}
		}
	return 0;
}

ll maxFlow() {
	ll flow = 0;
	while (BFS()) {
		for (int i = 0; i < n; ++i)
			work[i] = head[i];
		while (true) {
			int res = DFS(str, 2e9);
			if (!res)
				break;
			flow += res;
		}
	}
	return flow;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		head[i] = -1;
	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		--u;
		--v;
		addEdge(u, v, c, c);
	}
	str = 0;
	tar = n - 1;
	printf("%lld\n", maxFlow());
	return 0;
}
