#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int u, c, p, b;
	state(int u, int c, int p, int b) :
			u(u), c(c), p(p), b(b) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

const int N = 1e4;
int n, m, cost[N];
vector<pair<int, int> > g[N], G[N];
bool vis[N];
ll need;

void Dijkstra() {
	priority_queue<state> qu;
	qu.push(state(0, 0, -1, 0));
	while (!qu.empty()) {
		state e = qu.top();
		qu.pop();
		if (e.c > cost[e.u])
			continue;
		if (e.p != -1)
			G[e.u].push_back(make_pair(e.p, e.b));
		if (vis[e.u] || e.u == n - 1)
			continue;
		vis[e.u] = true;
		for (size_t i = 0; i < g[e.u].size(); ++i) {
			int u = g[e.u][i].first;
			int c = g[e.u][i].second + e.c;
			if (c > cost[u])
				continue;
			cost[u] = c;
			qu.push(state(u, c, e.u, g[e.u][i].second));
		}
	}
}

void DFS(int v) {
	if (v == 0 || vis[v])
		return;
	vis[v] = true;
	for (size_t i = 0; i < G[v].size(); ++i) {
		need += G[v][i].second * 2;
		DFS(G[v][i].first);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			vis[i] = false;
			cost[i] = 2e9;
		}
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}
		Dijkstra();
		for (int i = 0; i < n; ++i)
			vis[i] = false;
		need = 0;
		DFS(n - 1);
		printf("%lld\n", need);
	}
	return 0;
}
