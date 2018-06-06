#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100, oo = 1e9;
int n, m, cost[N], par[N], best, E[N][N];
vector<pair<int, int> > g[N];
priority_queue<pair<int, int> > qu;
bool vis[N];
vector<int> sol;

void Dijkstra(int src) {
	for (int i = 0; i < n; ++i)
		cost[i] = oo, vis[i] = false;
	cost[src] = 0;
	par[src] = -1;
	qu.push(make_pair(0, src));
	int from = -1, to = -1;
	while (!qu.empty()) {
		int v = qu.top().second, c = -qu.top().first;
		qu.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		for (int i = 0; i < (int) g[v].size(); ++i) {
			int u = g[v][i].first, nc = c + g[v][i].second;
			if (vis[u] || nc >= cost[u]) {
				if (u != par[v]) {
					int need = cost[v] + cost[u] + g[v][i].second;
					if (need < best) {
						from = v;
						to = u;
						best = need;
					}
				}
				continue;
			}
			par[u] = v;
			cost[u] = nc;
			qu.push(make_pair(-nc, u));
		}
	}
	if (from != -1) {
		sol.clear();
		for (int u = from; u != -1; u = par[u])
			sol.push_back(u);
		reverse(sol.begin(), sol.end());
		for (int u = to; u != src; u = par[u])
			sol.push_back(u);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) == 2 && n != -1) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			for (int j = i; j < n; ++j)
				E[i][j] = E[j][i] = oo;
		}
		while (m--) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u, --v;
			E[u][v] = E[v][u] = min(E[u][v], c);
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (E[i][j] != oo) {
					g[j].push_back(make_pair(i, E[i][j]));
					g[i].push_back(make_pair(j, E[i][j]));
				}
		best = oo;
		sol.clear();
		for (int i = 0; i < n; ++i)
			Dijkstra(i);
		if (sol.empty())
			puts("No solution.");
		else {
			for (int i = 0; i < (int) sol.size(); ++i)
				printf("%s%d", i ? " " : "", sol[i] + 1);
			puts("");
		}
	}
	return 0;
}
