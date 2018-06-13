#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, cap, cost;
	edge(int u, int v, int cap, int cost) :
			u(u), v(v), cap(cap), cost(cost) {
	}
};

const int N = 16, oo = 1e9;
int n, a[N], b[N], cost[5000], par[5000];
vector<edge> e;
vector<pair<int, int> > A, B;

inline void build(int *a, vector<pair<int, int> > &ones) {
	ones.clear();
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		for (int j = 0; x != 0; ++j, x >>= 1)
			if ((x & 1) == 1)
				ones.push_back(make_pair(i, j));
	}
}

inline void addEdge(int u, int v, int cap, int cost) {
	e.push_back(edge(u, v, cap, cost));
	e.push_back(edge(v, u, 0, -cost));
}

inline int calc(pair<int, int> &a, pair<int, int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool BellmanFord(int src, int sink) {
	for (int i = 0; i <= sink; ++i)
		cost[i] = oo;
	cost[src] = 0;
	bool ok = true;
	for (int it = 1; it <= sink && ok; ++it) {
		ok = false;
		for (int i = 0; i < (int) e.size(); ++i) {
			int u = e[i].u, v = e[i].v;
			if (e[i].cap != 0 && cost[u] < oo && cost[u] + e[i].cost < cost[v]) {
				ok = true;
				par[v] = i;
				cost[v] = cost[u] + e[i].cost;
			}
		}
	}
	return cost[sink] < oo;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		build(a, A);
		build(b, B);
		if (A.size() != B.size()) {
			puts("Impossible");
			continue;
		}
		int ones = A.size();
		e.clear();
		int src = 0, sink = (ones << 1) + 1;
		for (int i = 0; i < ones; ++i) {
			for (int j = 0; j < ones; ++j)
				addEdge(i + 1, j + 1 + ones, 1, calc(A[i], B[j]));
			addEdge(src, i + 1, 1, 0);
			addEdge(i + 1 + ones, sink, 1, 0);
		}
		int flow = 0, minCost = 0;
		while (BellmanFord(src, sink)) {
			minCost += cost[sink];
			++flow;
			for (int i = sink; i != src; i = e[par[i]].u) {
				--e[par[i]].cap;
				++e[par[i] ^ 1].cap;
			}
		}
		if (flow != ones)
			puts("Impossible");
		else
			printf("%d\n", minCost);
	}
	return 0;
}
