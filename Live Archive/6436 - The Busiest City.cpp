#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e4;
int n, par[N];
ll sz[N];
vector<int> g[N];

int DFS(int v, int p) {
	par[v] = p;
	for (size_t i = 0; i < g[v].size(); ++i)
		if (g[v][i] != p)
			sz[v] += DFS(g[v][i], v) + 1;
	return sz[v];
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			sz[i] = 0;
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		DFS(0, -1);
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			ll can = 0;
			for (size_t j = 0; j < g[i].size(); ++j)
				if (g[i][j] != par[i])
					can += (sz[i] - sz[g[i][j]] - 1) * (sz[g[i][j]] + 1);
			can /= 2;
			can += (n - sz[i] - 1) * sz[i];
			res = max(res, can);
		}
		printf("Case #%d: %lld\n", cas++, res);
	}
	return 0;
}
