#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, c, f, nxt;
	edge() {
	}
	edge(int u, int c, int f, int nxt) :
			u(u), c(c), f(f), nxt(nxt) {
	}
} e[30000];

const int N = 201;
int n, head[N], work[N], level[N], vis[N], qu[N], vs, idx;
double d;
pair<int, int> v[N];

void addEdge(int u, int v, int c) {
	e[idx] = edge(v, c, 0, head[u]);
	head[u] = idx++;
	e[idx] = edge(u, 0, 0, head[v]);
	head[v] = idx++;
}

double dist(int i, int j) {
	double x = v[i].first - v[j].first;
	double y = v[i].second - v[j].second;
	return sqrt(x * x + y * y);
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
		for (int i = 0; i <= n * 2; ++i)
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
		scanf("%d%lf", &n, &d);
		for (int i = 0; i <= n * 2; ++i)
			head[i] = -1;
		idx = 0;
		int all = 0;
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d%d%d%d", &v[i].first, &v[i].second, &a, &b);
			addEdge(0, i + 1, a);
			addEdge(i + 1, i + 1 + n, b);
			all += a;
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				double dd = dist(i, j);
				if (dd <= d) {
					addEdge(i + 1 + n, j + 1, 2e9);
					addEdge(j + 1 + n, i + 1, 2e9);
				}
			}
		vector<int> res;
		for (int i = 1; i <= n; ++i)
			if (maxFlow(0, i) == all)
				res.push_back(i - 1);
		if (!res.size())
			puts("-1");
		else {
			for (size_t i = 0; i < res.size(); ++i)
				printf("%s%d", i ? " " : "", res[i]);
			puts("");
		}
	}
	return 0;
}
