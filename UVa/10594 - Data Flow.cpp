#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v;
	ll cap, cost;
	edge(int u, int v, ll cap, ll cost) :
			u(u), v(v), cap(cap), cost(cost) {
	}
};

const int N = 101;
const ll oo = 1e18;
int n, m, par[N];
ll cost[N];
vector<edge> e;

void addEdge(int u, int v, ll f, ll c) {
	e.push_back(edge(u, v, f, c));
	e.push_back(edge(v, u, 0, -c));
}

bool BellmanFord(int src, int sink) {
	for (int i = 0; i <= n; ++i)
		cost[i] = oo;
	cost[src] = 0;
	for (int j = 0; j < n; ++j)
		for (size_t i = 0; i < e.size(); ++i) {
			int u = e[i].u, v = e[i].v;
			if (e[i].cap && cost[u] < oo && cost[u] + e[i].cost < cost[v]) {
				cost[v] = cost[u] + e[i].cost;
				par[v] = i;
			}
		}
	return cost[sink] < oo;
}

pair<ll, ll> minCostMaxFlow(int src, int sink) {
	ll maxFlow = 0, minCost = 0;
	while (BellmanFord(src, sink)) {
		ll flow = oo;
		for (int i = sink; i != src; i = e[par[i]].u)
			flow = min(flow, e[par[i]].cap);
		for (int i = sink; i != src; i = e[par[i]].u) {
			e[par[i]].cap -= flow;
			e[par[i] ^ 1].cap += flow;
		}
		maxFlow += flow;
		minCost += cost[sink] * flow;
	}
	return make_pair(maxFlow, minCost);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		e.clear();
		while (m-- != 0) {
			int u, v;
			ll c;
			scanf("%d%d%lld", &u, &v, &c);
			addEdge(u, v, 0, c);
			addEdge(v, u, 0, c);
		}
		ll d, k;
		scanf("%lld%lld", &d, &k);
		for (size_t i = 0; i < e.size(); i += 2)
			e[i].cap = k;
		addEdge(0, 1, d, 0);
		pair<ll, ll> res = minCostMaxFlow(0, n);
		if (res.first != d)
			puts("Impossible.");
		else
			printf("%lld\n", res.second);
	}
	return 0;
}
