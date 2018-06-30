#include <bits/stdc++.h>
using namespace std;

const int N = 120;
vector<int> g[N];
int n, m, match[N], vis[N], vs;

bool DFS(int v) {
	vis[v] = vs;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = match[g[v][i]];
		if (u == -1 || (vis[u] != vs && DFS(u))) {
			match[g[v][i]] = v;
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			match[i] = -1;
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
		}
		int res = n;
		for (int i = 0; i < n; ++i) {
			++vs;
			if (DFS(i))
				--res;
		}
		printf("%d\n", res);
	}
	return 0;
}
