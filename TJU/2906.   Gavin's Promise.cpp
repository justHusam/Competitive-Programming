#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, cap, cost;
	edge(int u, int v, int cap, int cost) :
			u(u), v(v), cap(cap), cost(cost) {
	}
};

vector<edge> e;
int par[201], cost[201];

inline void addEdge(int u, int v, int f, int c) {
	e.push_back(edge(u, v, f, c));
	e.push_back(edge(v, u, 0, -c));
}

int BellmanFord(int src, int sink) {
	for (int i = 0; i <= sink; ++i)
		cost[i] = 2e9;
	cost[src] = 0;
	for (int j = 0; j < sink; ++j)
		for (size_t i = 0; i < e.size(); ++i) {
			int u = e[i].u, v = e[i].v;
			if (e[i].cap && cost[u] < 2e9 && cost[u] + e[i].cost < cost[v]) {
				cost[v] = cost[u] + e[i].cost;
				par[v] = i;
			}
		}
	return cost[sink];
}

int minCostMaxFlow(int src, int sink) {
	int res1 = BellmanFord(src, sink);
	if (res1 == 2e9)
		return -1;
	for (int i = sink; i != src; i = e[par[i]].u) {
		--e[par[i]].cap;
		++e[par[i] ^ 1].cap;
	}
	int res2 = BellmanFord(src, sink);
	if (res2 == 2e9)
		return -1;
	return res1 + res2;
}

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) && n + m != 0) {
		e.clear();
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			addEdge(u + n, v, 1, c);
			addEdge(v + n, u, 1, c);
		}
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		--c;
		addEdge(a + n, n * 2, 1, 0);
		addEdge(b + n, n * 2, 1, 0);
		addEdge(c, c + n, 2, 0);
		for (int i = 0; i < n; ++i)
			if (i != c)
				addEdge(i, i + n, 1, 0);
		int res = minCostMaxFlow(c, n * 2);
		if (res == -1)
			puts("No Solution.");
		else
			printf("%d\n", res);
	}
	return 0;
}
