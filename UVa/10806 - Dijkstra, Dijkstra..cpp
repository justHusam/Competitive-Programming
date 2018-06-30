#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct edge {
	int u, v, cap, cost;
	edge(int u, int v, int cap, int cost) :
			u(u), v(v), cap(cap), cost(cost) {
	}
};

const int N = 100, oo = 2e9;
vector<edge> E;
int n, m, cost[N], par[N];

void addEdge(int u, int v, int c) {
	E.push_back(edge(u, v, 1, c));
	E.push_back(edge(v, u, 0, -c));
}

int BellmanFord(int src, int sink) {
	for (int i = 0; i < n; ++i)
		cost[i] = 2e9;
	cost[src] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (size_t j = 0; j < E.size(); ++j) {
			int u = E[j].u, v = E[j].v;
			if (E[j].cap && cost[u] < oo && cost[u] + E[j].cost < cost[v]) {
				cost[v] = cost[u] + E[j].cost;
				par[v] = j;
			}
		}
	return cost[sink];
}

int minCostMaxFlow(int src, int sink) {
	int res1 = BellmanFord(src, sink);
	if (res1 == oo)
		return -1;
	for (int i = sink; i != src; i = E[par[i]].u) {
		--E[par[i]].cap;
		++E[par[i] ^ 1].cap;
	}
	int res2 = BellmanFord(src, sink);
	if (res2 == oo)
		return -1;
	return res1 + res2;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		E.clear();
		scanf("%d", &m);
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			addEdge(u, v, c);
			addEdge(v, u, c);
		}
		int res = minCostMaxFlow(0, n - 1);
		if (res == -1)
			puts("Back to jail");
		else
			printf("%d\n", res);
	}
	return 0;
}