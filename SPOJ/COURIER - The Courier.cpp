#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, cost[N][N], from[12], to[12], all, src, with, q;
vector<pair<int, int> > g[N];
ll dp[N][1 << 12];
priority_queue<pair<int, int> > qu;
bool vis[N];

void Dijkstra(int src, int *cost) {
	for (int i = 0; i < n; ++i) {
		vis[i] = false;
		cost[i] = 2e9;
	}
	cost[src] = 0;
	qu.push(make_pair(0, src));
	while (!qu.empty()) {
		int v = qu.top().second, c = -qu.top().first;
		qu.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].first, nc = c + g[v][i].second;
			if (vis[u] || nc >= cost[u])
				continue;
			cost[u] = nc;
			qu.push(make_pair(-nc, u));
		}
	}
}

ll calc(int at, int msk) {
	if (msk == all)
		return cost[at][src];
	ll &res = dp[at][msk];
	if (res != -1)
		return res;
	res = 1LL << 62;
	for (int i = 0; i < with; ++i)
		if (((msk >> i) & 1) == 0)
			res = min(res, calc(to[i], msk | (1 << i)) + cost[at][from[i]] + cost[from[i]][to[i]]);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &src);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m--) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}
		for (int i = 0; i < n; ++i)
			Dijkstra(i, cost[i]);
		with = 0;
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			for (int j = 0; j < c; ++j) {
				from[j + with] = u;
				to[j + with] = v;
			}
			with += c;
		}
		memset(dp, -1, sizeof dp);
		all = (1 << with) - 1;
		--src;
		printf("%lld\n", calc(src, 0));
	}
	return 0;
}
