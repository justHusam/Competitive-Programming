#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
bool vis[N], ok;
vector<int> g[N];

void DFS(int v, int par) {
	vis[v] = true;
	for (size_t i = 0; i < g[v].size(); i++)
		if (vis[g[v][i]] && g[v][i] != par)
			ok = false;
		else if (!vis[g[v][i]])
			DFS(g[v][i], v);
}

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		ok = true;
		if (m + 1 != n)
			ok = false;
		for (int i = 0; i < n; ++i)
			g[i].clear();
		int u, v;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &u, &v);
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(vis, false, sizeof vis);
		for (int i = 0; i < n && ok; i++)
			for (size_t j = 0; j < g[i].size() && ok; j++)
				if (!vis[g[i][j]])
					DFS(g[i][j], -1);
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
