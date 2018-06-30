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

const int N = 40, oo = 2e9;
int n, m, vis[N][N], vs, cost[N * N + 2], par[N * N + 2];
char g[N][N + 1];
vector<pair<int, int> > a, b;
vector<edge> e;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
pair<int, int> qu[N * N];

void addEdge(int u, int v, int c) {
	e.push_back(edge(u, v, 1, c));
	e.push_back(edge(v, u, 0, -c));
}

void BFS(int u) {
	int s = 0, e = 0;
	qu[e++] = a[u];
	vis[a[u].first][a[u].second] = ++vs;
	int lev = 1;
	while (s < e) {
		int siz = e - s;
		while (siz--) {
			pair<int, int> fr = qu[s++];
			for (int i = 0; i < 4; ++i) {
				int tx = fr.first + dx[i];
				int ty = fr.second + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] == vs || g[tx][ty] == '#')
					continue;
				vis[tx][ty] = vs;
				if (g[tx][ty] == 'X') {
					int v = lower_bound(b.begin(), b.end(), make_pair(tx, ty)) - b.begin();
					addEdge(u + 1, v + a.size() + 1, lev);
				}
				qu[e++] = make_pair(tx, ty);
			}
		}
		++lev;
	}
}

int BellmanFord(int src, int sink) {
	for (int i = 0; i <= sink; ++i)
		cost[i] = oo;
	cost[src] = 0;
	bool can = true;
	for (int j = 0; j < sink && can; ++j) {
		can = false;
		for (size_t i = 0; i < e.size(); ++i) {
			int u = e[i].u, v = e[i].v;
			if (e[i].cap && cost[u] < oo && cost[u] + e[i].cost < cost[v]) {
				cost[v] = cost[u] + e[i].cost;
				par[v] = i;
				can = true;
			}
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
		for (int i = sink; i != src; i = e[par[i]].u) {
			--e[par[i]].cap;
			++e[par[i] ^ 1].cap;
		}
	}
	return minCost;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		a.clear();
		b.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == 'B')
					a.push_back(make_pair(i, j));
				else if (g[i][j] == 'X')
					b.push_back(make_pair(i, j));
			}
		e.clear();
		int src = 0, sink = a.size() + b.size() + 1;
		for (size_t i = 0; i < a.size(); ++i) {
			addEdge(src, i + 1, 0);
			BFS(i);
		}
		for (size_t i = 0; i < b.size(); ++i)
			addEdge(i + a.size() + 1, sink, 0);
		printf("%d\n", minCostMaxFlow(src, sink));
	}
	return 0;
}
