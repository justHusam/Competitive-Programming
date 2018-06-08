#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e6;
vector<pair<int, int> > g[N], rg[N];
int vis[N], cost[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear(), rg[i].clear(), cost[i] = 2e9, vis[i] = false;
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			g[u].push_back(make_pair(v, c));
			rg[v].push_back(make_pair(u, c));
		}
		priority_queue<pair<int, int> > qu;
		qu.push(make_pair(0, 0));
		cost[0] = 0;
		while (!qu.empty()) {
			const pair<int, int> e = qu.top();
			qu.pop();
			if (vis[e.second])
				continue;
			vis[e.second] = true;
			for (size_t i = 0; i < g[e.second].size(); ++i) {
				int u = g[e.second][i].first;
				int c = g[e.second][i].second - e.first;
				if (vis[u] || c >= cost[u])
					continue;
				cost[u] = c;
				qu.push(make_pair(-c, u));
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			res += cost[i];
			cost[i] = 2e9;
			vis[i] = false;
		}
		qu.push(make_pair(0, 0));
		cost[0] = 0;
		while (!qu.empty()) {
			const pair<int, int> e = qu.top();
			qu.pop();
			if (vis[e.second])
				continue;
			vis[e.second] = true;
			for (size_t i = 0; i < rg[e.second].size(); ++i) {
				int u = rg[e.second][i].first;
				int c = rg[e.second][i].second - e.first;
				if (vis[u] || c >= cost[u])
					continue;
				cost[u] = c;
				qu.push(make_pair(-c, u));
			}
		}
		for (int i = 0; i < n; ++i)
			res += cost[i];
		printf("%d\n", res);
	}
	return 0;
}
