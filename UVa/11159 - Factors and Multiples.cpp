#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, a[N], b[N], match[N], vis[N], vs;
vector<vector<int> > g;

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
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		g.clear();
		g.resize(n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if ((a[i] != 0 && b[j] % a[i] == 0) || b[j] == 0)
					g[i].push_back(j);
		memset(match, -1, sizeof match);
		int res = 0;
		for (int i = 0; i < n; ++i) {
			++vs;
			if (DFS(i))
				++res;
		}
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
