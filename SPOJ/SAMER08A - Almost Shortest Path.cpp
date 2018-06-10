#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct edge {
	int u, c, idx;
	edge(int u, int c, int idx) :
			u(u), c(c), idx(idx) {
	}
};

struct state {
	int u, c;
	state(int u, int c) :
			u(u), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

const int N = 500, M = 1e4 + 9;
vector<vector<pair<int, int> > > adj;
bitset<N> vis;
bitset<M> no;
vector<vector<edge> > g;
int cost[N];

inline void dfs(int v, int e) {
	no[e] = 1;
	if (vis[v])
		return;
	for (int a = 0; a < (int) adj[v].size(); ++a)
		dfs(adj[v][a].first, adj[v][a].second);
}

int main(int argc, char **argv) {
	while (true) {
		int n, m, str, tar;
		scanf("%d%d", &n, &m);
		if (n == 0)
			break;
		scanf("%d%d", &str, &tar);
		g.clear();
		g.resize(n);
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			g[u].push_back(edge(v, c, i));
		}
		if (g[str].size() == 1 || g[tar].size() == 1) {
			puts("-1");
			continue;
		}
		priority_queue<state> qu1, qu2;
		vis.reset();
		memset(cost, 0x3f, sizeof cost);
		cost[str] = 0;
		qu1.push(state(str, 0));
		bool can = false;
		adj.clear();
		adj.resize(n);
		while (!qu1.empty()) {
			const state E = qu1.top();
			qu1.pop();
			if (vis[E.u])
				continue;
			vis[E.u] = 1;
			if (E.u == tar) {
				can = true;
				no.reset();
				vis.reset();
				dfs(E.u, M - 5);
				break;
			}
			for (size_t i = 0; i < g[E.u].size(); ++i) {
				int u = g[E.u][i].u;
				int c = g[E.u][i].c + E.c;
				int e = g[E.u][i].idx;
				if (vis[u] || c > cost[u])
					continue;
				if (c < cost[u]) {
					adj[u].clear();
					cost[u] = c;
					qu1.push(state(u, c));
				}
				adj[u].push_back(make_pair(E.u, e));
			}
		}
		if (!can) {
			puts("-1");
			continue;
		}
		int res = -1;
		vis.reset();
		memset(cost, 0x3f, sizeof cost);
		cost[str] = 0;
		qu2.push(state(str, 0));
		while (!qu2.empty()) {
			const state E = qu2.top();
			qu2.pop();
			if (vis[E.u])
				continue;
			vis[E.u] = 1;
			if (E.u == tar) {
				res = E.c;
				break;
			}
			for (size_t i = 0; i < g[E.u].size(); ++i) {
				int u = g[E.u][i].u;
				int c = g[E.u][i].c + E.c;
				int e = g[E.u][i].idx;
				if (vis[u] || no[e] || c >= cost[u])
					continue;
				cost[u] = c;
				qu2.push(state(u, c));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
