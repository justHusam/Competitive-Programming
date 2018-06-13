#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 30;
vector<pair<int, int> > g[N];
int n, m, cost[N];
bool vis[N];

int Dijkstra(int src, int dest, int no) {
	for (int i = 0; i < n; ++i) {
		cost[i] = 2e9;
		vis[i] = false;
	}
	priority_queue<pair<int, int> > qu;
	qu.push(make_pair(0, src));
	cost[src] = 0;
	vis[no] = true;
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
	while (scanf("%d%d", &n, &m) && (n || m)) {
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			--a;
			--b;
			g[a].push_back(make_pair(b, c));
			g[b].push_back(make_pair(a, c));
		}
		int res = 0;
		for (int i = 1; i < n - 1; ++i) {
			int need = Dijkstra(0, n - 1, i);
			if (need == -1) {
				res = -1;
				break;
			}
			res = max(res, need);
		}
		if (res == -1)
			puts("Inf");
		else
			printf("%d\n", res);
	}
	return 0;
}
