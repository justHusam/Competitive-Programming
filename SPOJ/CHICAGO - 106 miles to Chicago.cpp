#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, double> > g[N];
int n, m;
double cost[N];
bool vis[N];

double Dijkstra(int src, int tar) {
	priority_queue<pair<double, int> > qu;
	qu.push(make_pair(0, src));
	cost[src] = 1;
	while (!qu.empty()) {
		pair<double, int> e = qu.top();
		qu.pop();
		if (e.second == tar)
			return (1 + e.first) * 100;
		if (vis[e.second])
			continue;
		vis[e.second] = true;
		for (size_t i = 0; i < g[e.second].size(); ++i) {
			int u = g[e.second][i].first;
			double p = 1 - (1 + e.first) * g[e.second][i].second;
			if (vis[u] || p >= cost[u])
				continue;
			cost[u] = p;
			qu.push(make_pair(-p, u));
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			cost[i] = 2e9;
			vis[i] = false;
		}
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			g[u].push_back(make_pair(v, c / 100.0));
			g[v].push_back(make_pair(u, c / 100.0));
		}
		printf("%.6lf percent\n", Dijkstra(0, n - 1));
	}
	return 0;
}
