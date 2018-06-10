#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 200;
int n, m, g[N][N];
vector<int> G[N];
bool vis[N];

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int u;
		scanf("%d", &n);
		scanf("%d", &m);
		for (int i = 0; i < n; ++i) {
			memset(g[i], 0, sizeof g[i]);
			G[i].clear();
		}
		while (m-- != 0) {
			scanf("%d", &u);
			--u;
			g[0][u] = 1;
			G[0].push_back(u);
			G[u].push_back(0);
		}
		for (int i = 1; i < n - 1; ++i) {
			scanf("%d", &m);
			while (m-- != 0) {
				scanf("%d", &u);
				--u;
				if (u == n - 1)
					g[i][u] = 1;
				else
					g[i][u] = 1e9;
				G[i].push_back(u);
				G[u].push_back(i);
			}
		}
		int flow = 0, src = 0, sink = n - 1;
		while (true) {
			memset(vis, false, sizeof vis);
			queue<int> qu;
			qu.push(src);
			vis[src] = true;
			bool can = false;
			vector<int> par(n, -1);
			while (!qu.empty()) {
				int u = qu.front();
				qu.pop();
				if (u == sink) {
					can = true;
					break;
				}
				for (size_t i = 0; i < G[u].size(); ++i)
					if (g[u][G[u][i]] && !vis[G[u][i]]) {
						par[G[u][i]] = u;
						vis[G[u][i]] = 1;
						qu.push(G[u][i]);
					}
			}
			if (!can)
				break;
			++flow;
			for (int u = sink; u != src; u = par[u]) {
				int v = par[u];
				++g[u][v];
				--g[v][u];
			}
		}
		printf("%d\n", flow);
	}
	return 0;
}
