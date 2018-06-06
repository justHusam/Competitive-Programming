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

const int N = 16, oo = 2e9;
int n, vis[N][N], vs, cost[N * 2 + 2], par[N * 2 + 2];
pair<int, int> qu[N * N], a[N], b[N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
vector<edge> e;

int BFS(int src, int dest) {
	if (a[src] == b[dest])
		return 0;
	int s = 0, e = 0, lev = 1;
	qu[e++] = a[src];
	vis[a[src].first][a[src].second] = ++vs;
	while (s < e) {
		int siz = e - s;
		while (siz--) {
			pair<int, int>&fr = qu[s++];
			for (int i = 0; i < 4; ++i) {
				int tx = fr.first + dx[i];
				int ty = fr.second + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n || vis[tx][ty] == vs)
					continue;
				if (make_pair(tx, ty) == b[dest])
					return lev;
				vis[tx][ty] = vs;
				qu[e++] = make_pair(tx, ty);
			}
		}
		++lev;
	}
	return oo;
}

void addEdge(int u, int v, int c) {
	e.push_back(edge(u, v, 1, c));
	e.push_back(edge(v, u, 0, -c));
}

int BellmanFord(int src, int sink) {
	for (int i = 0; i <= sink; ++i)
		cost[i] = oo;
	cost[src] = 0;
	for (int j = 0; j < sink; ++j)
		for (size_t i = 0; i < e.size(); ++i) {
			int u = e[i].u, v = e[i].v;
			if (e[i].cap && cost[u] < oo && cost[u] + e[i].cost < cost[v]) {
				cost[v] = cost[u] + e[i].cost;
				par[v] = i;
			}
		}
	return cost[sink];
}

int minCostMaxFlow(int src, int sink) {
	int minCost = 0;
	while (true) {
		int res = BellmanFord(src, sink);
		if (res == oo)
			break;
		minCost += res;
		for (int u = sink; u != src; u = e[par[u]].u) {
			--e[par[u]].cap;
			++e[par[u] ^ 1].cap;
		}
	}
	return minCost;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i].second);
			--a[i].second;
			a[i].first = i;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &b[i].second);
			--b[i].second;
			b[i].first = i;
		}
		e.clear();
		int src = 0, sink = n * 2 + 1;
		for (int i = 0; i < n; ++i) {
			addEdge(src, i + 1, 0);
			for (int j = 0; j < n; ++j)
				addEdge(i + 1, j + n + 1, BFS(i, j));
			addEdge(i + n + 1, sink, 0);
		}
		printf("%d\n", minCostMaxFlow(src, sink));
	}
	return 0;
}
