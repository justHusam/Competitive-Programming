#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 150;
int n, src, dest, cost[N];
vector<pair<int, int> > g[N];
bool vis[N];
vector<int> v;

int Dijkstra() {
	priority_queue<pair<int, int> > qu;
	qu.push(make_pair(0, src));
	cost[src] = 0;
	while (!qu.empty()) {
		pair<int, int> e = qu.top();
		qu.pop();
		if (e.second == dest)
			return -e.first;
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
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &src, &dest) && n != 0) {
		for (int i = 0; i < N; ++i) {
			g[i].clear();
			vis[i] = false;
			cost[i] = 2e9;
		}
		for (int i = 0, x; i < n; ++i) {
			v.clear();
			scanf("%d", &x);
			v.resize(x);
			for (int j = 0; j < x; ++j)
				scanf("%d", &v[j]);
			for (int j = 0; j < x; ++j)
				for (int k = j + 1; k < x; ++k) {
					g[v[j]].push_back(make_pair(v[k], abs(v[j] - v[k])));
					g[v[k]].push_back(make_pair(v[j], abs(v[j] - v[k])));
				}
		}
		printf("%d\n", Dijkstra());
	}
	return 0;
}
