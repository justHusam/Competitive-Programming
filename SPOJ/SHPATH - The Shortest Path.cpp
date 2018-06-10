#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

char lst[10001][12];

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		vector<vector<pair<int, int> > > g(n);
		for (int i = 0; i < n; ++i) {
			int r;
			scanf("%s%d", lst[i], &r);
			while (r-- != 0) {
				int u, c;
				scanf("%d%d", &u, &c);
				--u;
				g[i].push_back(make_pair(u, c));
			}
		}
		int q;
		scanf("%d", &q);
		while (q-- != 0) {
			char f[15], t[15];
			scanf("%s%s", f, t);
			int str = -1, dest = -1;
			for (int i = 0; i < n; ++i) {
				if (!strcmp(f, lst[i]))
					str = i;
				if (!strcmp(t, lst[i]))
					dest = i;
				if (str != -1 && dest != -1)
					break;
			}
			vector<int> cost(n, 2e9);
			vector<bool> vis(n, false);
			cost[str] = 0;
			priority_queue<pair<int, int> > qu;
			qu.push(make_pair(0, str));
			while (!qu.empty()) {
				pair<int, int> e = qu.top();
				qu.pop();
				if (vis[e.second])
					continue;
				vis[e.second] = true;
				if (e.second == dest) {
					printf("%d\n", -e.first);
					break;
				}
				for (size_t i = 0; i < g[e.second].size(); ++i) {
					int u = g[e.second][i].first;
					int c = g[e.second][i].second - e.first;
					if (vis[u] || c >= cost[u])
						continue;
					cost[u] = c;
					qu.push(make_pair(-c, u));
				}
			}
		}
	}
	return 0;
}
