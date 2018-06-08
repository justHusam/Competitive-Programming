#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m, str, tar;
		scanf("%d%d%d%d", &n, &m, &str, &tar);
		--str, --tar;
		vector<vector<pair<int, int> > > g(n);
		while (m-- != 0) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			--a, --b;
			g[a].push_back(make_pair(b, c));
			g[b].push_back(make_pair(a, c));
		}
		vector<bool> vis(n, false);
		vector<ll> cost(n, INT_MAX);
		priority_queue<pair<int, int> > qu;
		qu.push(make_pair(0, str));
		cost[str] = 0;
		int res = -1;
		while (!qu.empty()) {
			pair<int, int> temp = qu.top();
			qu.pop();
			if (temp.second == tar) {
				res = -temp.first;
				break;
			}
			if (vis[temp.second])
				continue;
			vis[temp.second] = true;
			for (size_t i = 0; i < g[temp.second].size(); ++i) {
				int v = g[temp.second][i].first;
				ll c = -temp.first + g[temp.second][i].second;
				if (vis[v] || c >= cost[v])
					continue;
				cost[v] = c;
				qu.push(make_pair(-c, v));
			}
		}
		if (res == -1)
			puts("NONE");
		else
			printf("%d\n", res);
	}
	return 0;
}
