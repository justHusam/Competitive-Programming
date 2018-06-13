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

const int N = 128, oo = 2e9;
vector<edge> E;
int n, m, cost[N], par[N];

void addEdge(int u, int v, int c) {
	E.push_back(edge(u, v, 1, c));
	E.push_back(edge(v, u, 0, -c));
}

int BellmanFord(int src, int sink) {
	for (int i = 0; i < n; ++i)
		cost[i] = oo;
	cost[src] = 0;
	for (int j = 0; j < n - 1; ++j)
		for (size_t i = 0; i < E.size(); ++i) {
			int u = E[i].u, v = E[i].v;
			if (E[i].cap && cost[u] < oo && cost[u] + E[i].cost < cost[v]) {
				cost[v] = cost[u] + E[i].cost;
				par[v] = i;
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
	int k = 1;
	while (scanf("%d%d", &n, &m) && n + m > 0) {
		E.clear();
		for (int i = 0; i < n; ++i)
			addEdge(i, i + n, 0);
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, c);
		}
		int res = minCostMaxFlow(0, n - 1);
		printf("Instance #%d: ", k++);
		if (res == -1)
			puts("Not possible");
		else
			printf("%d\n", res);
	}
	return 0;
}
