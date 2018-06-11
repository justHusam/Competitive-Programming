#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int u, v, c;
	state() {
	}
	state(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
};

const int N = 1e4, oo = 1e9;
int n, m, k, src, dest, from[N], to[N];
vector<pair<int, int> > g[N];
vector<state> e, all;
bool vis[N];
priority_queue<pair<int, int> > qu;

void Dijkstra(int src, int *cost) {
	for (int i = 0; i < n; ++i)
		vis[i] = false;
	cost[src] = 0;
	qu.push(make_pair(0, src));
	while (!qu.empty()) {
		int v = qu.top().second, c = -qu.top().first;
		qu.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		for (size_t i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].first, nc = c + g[v][i].second;
			if (vis[u] || nc >= cost[u])
				continue;
			cost[u] = nc;
			qu.push(make_pair(-nc, u));
		}
	}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d%d%d", &n, &m, &k, &src, &dest);
		--src;
		--dest;
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			from[i] = to[i] = oo;
		}
		all.clear();
		all.resize(m);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &all[i].u, &all[i].v, &all[i].c);
			--all[i].u;
			--all[i].v;
			g[all[i].u].push_back(make_pair(all[i].v, all[i].c));
		}
		e.clear();
		e.resize(k);
		for (int i = 0; i < k; ++i) {
			scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
			--e[i].u;
			--e[i].v;
		}
		Dijkstra(src, to);
		if (to[dest] == oo) {
			puts("-1");
			continue;
		}
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 0; i < m; ++i)
			g[all[i].v].push_back(make_pair(all[i].u, all[i].c));
		Dijkstra(dest, from);
		int res = to[dest];
		for (int i = 0; i < k; ++i) {
			res = min(res, to[e[i].u] + e[i].c + from[e[i].v]);
			res = min(res, to[e[i].v] + e[i].c + from[e[i].u]);
		}
		printf("%d\n", res);
	}
	return 0;
}
