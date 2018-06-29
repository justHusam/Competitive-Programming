#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, q, par[N], dep[N];
pair<int, ll> dp[N][18];
vector<pair<int, int> > g[N];

void DFS(int v) {
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i].first;
		if (u != par[v]) {
			par[u] = v;
			dep[u] = dep[v] + 1;
			dp[u][0] = make_pair(v, g[v][i].second);
			DFS(u);
		}
	}
}

ll LCA(int u, int v) {
	if (dep[v] < dep[u])
		swap(u, v);
	int log = 0;
	while ((1 << log) <= dep[v])
		++log;
	--log;
	ll res = 0;
	for (int i = log; i >= 0; --i)
		if (dep[v] - (1 << i) >= dep[u]) {
			res += dp[v][i].second;
			v = dp[v][i].first;
		}
	if (v == u)
		return res;
	for (int i = log; i >= 0; --i)
		if (dp[u][i].first != -1 && dp[v][i].first != -1 && dp[u][i].first != dp[v][i].first) {
			res += dp[u][i].second + dp[v][i].second;
			u = dp[u][i].first;
			v = dp[v][i].first;
		}
	res += dp[u][0].second + dp[v][0].second;
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			memset(dp[i], -1, sizeof dp[i]);
		}
		for (int i = 1; i < n; ++i) {
			int u, c;
			scanf("%d%d", &u, &c);
			g[i].push_back(make_pair(u, c));
			g[u].push_back(make_pair(i, c));
		}
		par[0] = -1;
		dep[0] = 0;
		dp[0][0] = make_pair(-1, 0);
		DFS(0);
		for (int j = 1; (1 << j) < n; ++j)
			for (int i = 0; i < n; ++i)
				if (dp[i][j - 1].first != -1) {
					dp[i][j].first = dp[dp[i][j - 1].first][j - 1].first;
					dp[i][j].second = dp[i][j - 1].second + dp[dp[i][j - 1].first][j - 1].second;
				}
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%s%lld", i ? " " : "", LCA(u, v));
		}
		puts("");
	}
	return 0;
}
