#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;
vector<pair<int, int> > g[10009];
priority_queue<pair<int, int> > qu;
vector<int> cost;
vector<bool> vis;

int Dijkstra(int src, int dest) {
	cost[src] = 0;
	qu.push(make_pair(0, src));
	while (!qu.empty()) {
		pair<int, int> temp = qu.top();
		qu.pop();
		if (vis[temp.second])
			continue;
		vis[temp.second] = true;
		for (size_t i = 0; i < g[temp.second].size(); ++i) {
			int v = g[temp.second][i].first;
			int nc = cost[temp.second] + g[temp.second][i].second;
			if (!vis[v] && nc < cost[v]) {
				cost[v] = nc;
				qu.push(make_pair(-cost[v], v));
			}
		}
	}
	return cost[dest];
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		cost.clear();
		cost.resize(n + 1, oo);
		vis.clear();
		vis.resize(n + 1, false);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		int a, b, c;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			g[a].push_back(make_pair(b, c));
		}
		scanf("%d%d", &a, &b);
		int res = Dijkstra(a, b);
		if (res == oo)
			printf("NO\n");
		else
			printf("%d\n", res);
	}
	return 0;
}
