#include <bits/stdc++.h>
using namespace std;

bool vis[2010];
vector<int> g[2005];
int n, m, type[2005];

void DFS(int v, int gen) {
	vis[v] = true;
	if (v != 0)
		type[v] = gen == -1 ? 1 : -1;
	for (size_t i = 0; i < g[v].size(); ++i) {
		if (!vis[g[v][i]])
			DFS(g[v][i], type[v]);
	}
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		memset(vis, false, sizeof vis);
		memset(type, 0, sizeof type);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		int c, d;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &c, &d);
			--c, --d;
			g[c].push_back(d);
			g[d].push_back(c);
		}
		type[0] = -1;
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				DFS(i, type[i]);
		bool ok = true;
		for (int i = 0; i < n && ok; i++)
			for (size_t j = 0; j < g[i].size() && ok; j++)
				if (type[i] == type[g[i][j]])
					ok = false;
		if (!ok)
			printf("Scenario #%d:\nSuspicious bugs found!\n", it);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n", it);
	}
	return 0;
}
