#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 50000;
bitset<N> vis;
vector<vector<pair<int, int> > > g;
pair<int, int> mx;

void dfs(int v, int d) {
	if (d >= mx.first)
		mx = make_pair(d, v);
	vis[v] = 1;
	for (int a = 0; a < (int) g[v].size(); ++a) {
		int u = g[v][a].first, c = d + g[v][a].second;
		if (!vis[u])
			dfs(u, c);
	}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		g.clear();
		g.resize(n);
		for (int a = 0; a < n - 1; ++a) {
			int x, y, l;
			scanf("%d%d%d", &x, &y, &l);
			--x, --y;
			g[x].push_back(make_pair(y, l));
			g[y].push_back(make_pair(x, l));
		}
		vis.reset();
		mx.first = 0;
		dfs(0, 0);
		vis.reset();
		dfs(mx.second, 0);
		printf("%d\n", mx.first);
	}
	return 0;
}
