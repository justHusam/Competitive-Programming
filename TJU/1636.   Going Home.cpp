#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, cap, cost;
	edge(int u, int v, int cap, int cost) :
			u(u), v(v), cap(cap), cost(cost) {
	}
};

const int oo = 2e9;
int n, m, cost[202], par[202];
char g[100][101];
vector<pair<int, int> > home, man;
vector<edge> e;

inline void addEdge(int u, int v, int f, int c) {
	e.push_back(edge(u, v, f, c));
	e.push_back(edge(v, u, 0, -c));
}

bool BellmanFord(int src, int sink) {
	for (int i = 0; i <= sink; ++i)
		cost[i] = oo;
	cost[src] = 0;
	bool ok = true;
	for (int it = 0; it < sink && ok; ++it) {
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

int minCostMaxFlow(int src, int sink) {
	int minCost = 0;
	while (BellmanFord(src, sink)) {
		for (int i = sink; i != src; i = e[par[i]].u) {
			--e[par[i]].cap;
			++e[par[i] ^ 1].cap;
		}
		minCost += cost[sink];
	}
	return minCost;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		home.clear();
		man.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == 'H')
					home.push_back(make_pair(i, j));
				else if (g[i][j] == 'm')
					man.push_back(make_pair(i, j));
			}
		e.clear();
		int src = 0, sink = home.size() + man.size() + 1;
		for (size_t i = 0; i < man.size(); ++i)
			addEdge(src, i + 1, 1, 0);
		for (size_t i = 0; i < home.size(); ++i)
			addEdge(i + man.size() + 1, sink, 1, 0);
		for (size_t i = 0; i < man.size(); ++i)
			for (size_t j = 0; j < home.size(); ++j) {
				int c = abs(man[i].first - home[j].first) + abs(man[i].second - home[j].second);
				addEdge(i + 1, j + man.size() + 1, 1, c);
			}
		printf("%d\n", minCostMaxFlow(src, sink));
	}
	return 0;
}
