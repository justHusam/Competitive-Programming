#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
vector<pair<int, int> > g[N];
bool vis[N];
int cost[N];

int main() {
	int t, cas = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			vis[i] = false;
			cost[i] = 2e9;
		}
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u, --v;
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}
		int src, dest;
		scanf("%d%d", &src, &dest);
		--src, --dest;
		priority_queue<pair<int, int> > qu;
		cost[src] = 0;
		qu.push(make_pair(0, src));
		while (qu.size()) {
			pair<int, int> e = qu.top();
			qu.pop();
			if (e.second == dest) {
				printf("Case %d: %d\n", cas++, -e.first);
				break;
			}
			if (vis[e.second])
				continue;
			vis[e.second] = true;
			for (size_t i = 0; i < g[e.second].size(); ++i) {
				int u = g[e.second][i].first;
				int nc = g[e.second][i].second - e.first;
				if (vis[u] || nc >= cost[u])
					continue;
				cost[u] = nc;
				qu.push(make_pair(-nc, u));
			}
		}
	}
	return 0;
}
