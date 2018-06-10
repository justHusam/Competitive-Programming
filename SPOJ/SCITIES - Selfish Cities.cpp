#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, cap, cost;
	edge(int u, int v, int cap, int cost) :
			u(u), v(v), cap(cap), cost(cost) {
	}
};

const int N = 202, oo = 2e9;
int n, m, cost[N], par[N];
vector<edge> e;

void addEdge(int u, int v, int c) {
	e.push_back(edge(u, v, 1, -c));
	e.push_back(edge(v, u, 0, c));
}

bool bellmanFord(int src, int sink) {
	for (int i = 0; i <= sink; ++i)
		cost[i] = oo;
	cost[src] = 0;
	bool ok = true;
	for (int j = 1; j <= sink && ok; ++j) {
		ok = false;
		for (size_t i = 0; i < e.size(); ++i) {
			int u = e[i].u, v = e[i].v;
			if (e[i].cap && cost[u] < oo && cost[u] + e[i].cost < cost[v]) {
				cost[v] = cost[u] + e[i].cost;
				par[v] = i;
				ok = true;
			}
		}
	}
	return cost[sink] < oo;
}

int maxFlow(int src, int sink) {
	int res = 0;
	while (bellmanFord(src, sink)) {
		res -= cost[sink];
		for (int i = sink; i != src; i = e[par[i]].u) {
			--e[par[i]].cap;
			++e[par[i] ^ 1].cap;
		}
	}
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		e.clear();
		int src = 0, sink = n + m + 1;
		for (int i = 1; i <= n; ++i)
			addEdge(src, i, 0);
		for (int i = 1; i <= m; ++i)
			addEdge(i + n, sink, 0);
		int u, v, c;
		while (scanf("%d%d%d", &u, &v, &c) && (u + v + c))
			addEdge(u, v + n, c);
		printf("%d\n", maxFlow(src, sink));
	}
	return 0;
}
