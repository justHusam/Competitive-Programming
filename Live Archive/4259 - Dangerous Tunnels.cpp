#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, cap, f, cost;
	edge(int u, int v, int cap, int f, int cost) :
			u(u), v(v), cap(cap), f(f), cost(cost) {
	}
};

const int N = 404, oo = 2e9;
vector<edge> e;
int n, m, k, cost[N], par[N];

void addEdge(int u, int v, int f, int c) {
	e.push_back(edge(u, v, f, 0, c));
	e.push_back(edge(v, u, 0, 0, -c));
}

bool bellmanFord(int src, int sink, int can) {
	for (int i = 0; i < n * 2; ++i)
		cost[i] = oo;
	cost[src] = 0;
	bool ok = true;
	for (int it = 1; it < n * 2 && ok; ++it) {
		ok = false;
		for (size_t i = 0; i < e.size(); ++i) {
			int u = e[i].u, v = e[i].v;
			if (e[i].f < e[i].cap && e[i].cost <= can && cost[u] < oo && cost[u] + e[i].cost < cost[v]) {
				cost[v] = cost[u] + e[i].cost;
				par[v] = i;
				ok = true;
			}
		}
	}
	return cost[sink] < oo;
}

int minCostMaxFlow(int src, int sink, int can) {
	for (size_t i = 0; i < e.size(); ++i)
		e[i].f = 0;
	int res = 0, flow = 0;
	while (bellmanFord(src, sink, can)) {
		int mx = 0;
		for (int i = sink; i != src; i = e[par[i]].u) {
			if (e[par[i]].cost)
				mx = max(mx, e[par[i]].cost);
			++e[par[i]].f;
			--e[par[i] ^ 1].f;
		}
		res = max(res, mx);
		++flow;
	}
	if (flow != k)
		res = -1;
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) && n != 0) {
		e.clear();
		n += 2;
		for (int i = 1; i < n; ++i)
			addEdge(i, i + n, 1, 0);
		scanf("%d", &m);
		int mx = 0;
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			if (v < u)
				swap(u, v);
			addEdge(u + n, v, 1, c);
			mx = max(mx, c);
		}
		scanf("%d", &k);
		addEdge(0, n, k, 0);
		int l = 1, r = mx + 10, res = 2e9;
		while (l <= r) {
			int m = (l + r) >> 1;
			int val = minCostMaxFlow(0, n - 1, m);
			if (val != -1) {
				res = val;
				r = m - 1;
			} else
				l = m + 1;
		}
		printf("Case %d: ", cas++);
		if (res == 2e9)
			puts("no solution");
		else
			printf("%d\n", res);
	}
	return 0;
}
