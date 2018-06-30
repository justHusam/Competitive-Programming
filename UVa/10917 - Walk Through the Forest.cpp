#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, m, dp[N], cost[N];
vector<pair<int, int> > g[N];
vector<int> G[N];
bool vis[N];

void Dijkstra() {
	priority_queue<pair<int, int> > qu;
	qu.push(make_pair(0, 1));
	cost[1] = 0;
	while (!qu.empty()) {
		pair<int, int> e = qu.top();
		qu.pop();
		if (vis[e.second])
			continue;
		vis[e.second] = true;
		for (size_t i = 0; i < g[e.second].size(); ++i) {
			int u = g[e.second][i].first;
			int c = -e.first + g[e.second][i].second;
			if (vis[u] || c >= cost[u])
				continue;
			cost[u] = c;
			qu.push(make_pair(-c, u));
		}
	}
}

int calc(int v) {
	if (v == 1)
		return 1;
	int &res = dp[v];
	if (res != -1)
		return res;
	res = 0;
	for (size_t i = 0; i < G[v].size(); ++i)
		res += calc(G[v][i]);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		scanf("%d", &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			dp[i] = -1;
			cost[i] = 2e9;
			vis[i] = false;
		}
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}
		Dijkstra();
		for (int i = 0; i < n; ++i) {
			int mn = 2e9;
			for (size_t j = 0; j < g[i].size(); ++j)
				mn = min(mn, cost[g[i][j].first] + g[i][j].second);
			for (size_t j = 0; j < g[i].size(); ++j)
				if (cost[g[i][j].first] < mn)
					G[i].push_back(g[i][j].first);
		}
		printf("%d\n", calc(0));
	}
	return 0;
}
