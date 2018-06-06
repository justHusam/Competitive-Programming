#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
int n, m, low[N], idx[N], id, comp[N], cnt, par[N], a[N], at[N], dp[N];
vector<int> g[N], G[N];
vector<pair<int, int> > br;
bool vis[N];

void DFS(int v, int p) {
	low[v] = idx[v] = ++id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!idx[u]) {
			DFS(u, v);
			if (low[u] > idx[v])
				br.push_back(make_pair(min(u, v), max(u, v)));
			low[v] = min(low[v], low[u]);
		} else if (u != p)
			low[v] = min(low[v], idx[u]);
	}
}

void DFS(int v) {
	comp[v] = cnt;
	vis[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!vis[u] && !binary_search(br.begin(), br.end(), make_pair(min(u, v), max(u, v))))
			DFS(u);
	}
}

int calc(int v, int p) {
	par[v] = p;
	dp[v] = at[v];
	for (size_t i = 0; i < G[v].size(); ++i)
		if (G[v][i] != p)
			dp[v] += calc(G[v][i], v);
	return dp[v];
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			dp[i] = at[i] = idx[i] = 0;
			vis[i] = false;
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		cnt = id = 0;
		br.clear();
		DFS(0, -1);
		if (!br.size()) {
			puts("No apple");
			continue;
		}
		sort(br.begin(), br.end());
		for (int i = 0; i < n; ++i)
			if (!vis[i]) {
				DFS(i);
				++cnt;
			}
		for (int i = 0; i < n; ++i) {
			for (size_t j = 0; j < g[i].size(); ++j)
				if (comp[i] != comp[g[i][j]])
					G[comp[i]].push_back(comp[g[i][j]]);
			at[comp[i]] += a[i];
		}
		for (int i = 0; i < cnt; ++i) {
			sort(G[i].begin(), G[i].end());
			G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
		}
		calc(0, -1);
		int best = -2e9;
		for (size_t i = 0; i < br.size(); ++i) {
			int u = comp[br[i].first], v = comp[br[i].second];
			if (par[u] == v)
				best = max(best, dp[u]);
			else
				best = max(best, dp[v]);
		}
		printf("%d\n", best);
	}
	return 0;
}
