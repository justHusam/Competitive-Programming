#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

struct node {
	int u, v, c;
	node(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
};

int pow(int x, int y) {
	return (x - y) * (x - y) * (x - y);
}

int main(int argc, char **argv) {
	int n, caseN = 1;
	while (scanf("%d", &n) > 0) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		vector<node> g;
		vector<vector<int> > G(n);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			G[x].push_back(y);
			g.push_back(node(x, y, pow(v[y], v[x])));
		}
		int q;
		scanf("%d", &q);
		printf("Set #%d\n", caseN++);
		vector<int> cost(n, 1e9);
		cost[0] = 0;
		for (int i = 0; i < n - 1; ++i)
			for (int j = 0; j < m; ++j) {
				int u = g[j].u, v = g[j].v, c = g[j].c;
				if (cost[u] != 1e9)
					cost[v] = min(cost[v], cost[u] + c);
			}
		vector<bool> in(n, false), vis(n, false);
		for (int i = 0; i < m; ++i) {
			int u = g[i].u, v = g[i].v, c = g[i].c;
			if (cost[u] + c < cost[v])
				in[u] = in[v] = true;
		}
		for (int i = 0; i < n; ++i) {
			if (!in[i] || vis[i])
				continue;
			queue<int> qu;
			vis[i] = true;
			cost[i] = -1;
			qu.push(i);
			while (!qu.empty()) {
				int v = qu.front();
				qu.pop();
				for (size_t j = 0; j < G[v].size(); ++j) {
					int u = G[v][j];
					if (vis[u])
						continue;
					vis[u] = true;
					cost[u] = -1;
					qu.push(u);
				}
			}
		}
		while (q-- != 0) {
			int d;
			scanf("%d", &d);
			--d;
			if (cost[d] < 3 || cost[d] == 1e9)
				puts("?");
			else
				printf("%d\n", cost[d]);
		}
	}
	return 0;
}
