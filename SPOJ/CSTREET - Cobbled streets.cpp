#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int p, n, m;
		scanf("%d%d%d", &p, &n, &m);
		vector<vector<pair<int, int> > > g(n);
		while (m--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			--a, --b;
			g[a].push_back(make_pair(b, c));
			g[b].push_back(make_pair(a, c));
		}
		ll res = 0;
		priority_queue<pair<int, int> > qu;
		vector<bool> vis(n);
		qu.push(make_pair(0, 0));
		while (!qu.empty()) {
			pair<int, int> temp = qu.top();
			qu.pop();
			if (vis[temp.second])
				continue;
			vis[temp.second] = true;
			res += -temp.first;
			for (size_t i = 0; i < g[temp.second].size(); ++i) {
				int v = g[temp.second][i].first;
				int c = g[temp.second][i].second;
				if (vis[v])
					continue;
				qu.push(make_pair(-c, v));
			}
		}
		printf("%lld\n", res * p);
	}
	return 0;
}
