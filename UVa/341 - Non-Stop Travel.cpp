#include <bits/stdc++.h>
using namespace std;

const int N = 12;
vector<vector<pair<int, int> > > g;
int cost[N], par[N];
bool vis[N];

void build(int v) {
	if (v != -1) {
		build(par[v]);
		printf(" %d", v);
	}
}

void Dijkstra(int caseN, int src, int dest) {
	priority_queue<pair<int, int> > qu;
	memset(vis, false, sizeof vis);
	memset(cost, 0x3f, sizeof cost);
	par[src] = -1;
	qu.push( { 0, src });
	while (!qu.empty()) {
		pair<int, int> e = qu.top();
		qu.pop();
		if (e.second == dest) {
			printf("Case %d: Path =", caseN);
			build(dest);
			printf("; %d second delay\n", cost[dest]);
			return;
		}
		if (vis[e.second])
			continue;
		vis[e.second] = true;
		for (size_t i = 0; i < g[e.second].size(); ++i) {
			int v = g[e.second][i].first;
			int c = -e.first + g[e.second][i].second;
			if (!vis[v] && c < cost[v]) {
				par[v] = e.second;
				cost[v] = c;
				qu.push( { -cost[v], v });
			}
		}
	}
}

int main(int argc, char **argv) {
	int n, caseN = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		g.clear();
		g.resize(n + 1);
		int m, v, c;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			while (m-- != 0) {
				scanf("%d%d", &v, &c);
				g[i].push_back( { v, c });
			}
		}
		int src, dest;
		scanf("%d%d", &src, &dest);
		Dijkstra(caseN++, src, dest);
	}
	return 0;
}
