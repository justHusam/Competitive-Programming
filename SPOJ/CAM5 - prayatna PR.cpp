#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, e;
		scanf("%d%d", &n, &e);
		vector<vector<int> > g(n);
		while (e--) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		bitset<100002> vis;
		vis.reset();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (vis[i])
				continue;
			++res;
			queue<int> qu;
			vis[i] = true;
			qu.push(i);
			while (!qu.empty()) {
				const int v = qu.front();
				qu.pop();
				for (size_t j = 0; j < g[v].size(); ++j) {
					int u = g[v][j];
					if (vis[u])
						continue;
					vis[u] = true;
					qu.push(u);
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
