#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, par[N], dep[N], parC[N], dp[N][18], sz[N];
vector<int> g[N];
set<pair<int, int> > at[N];
bool ok[N], col[N];

void DFS(int v) {
	for (int i = 0; i < (int) g[v].size(); ++i)
		if (g[v][i] != par[v]) {
			par[g[v][i]] = v;
			dep[g[v][i]] = dep[v] + 1;
			DFS(g[v][i]);
		}
}

void fullSize(int v, int p) {
	sz[v] = 1;
	for (int i = 0; i < (int) g[v].size(); ++i)
		if (g[v][i] != p && !ok[g[v][i]]) {
			fullSize(g[v][i], v);
			sz[v] += sz[g[v][i]];
		}
}

int findCenter(int v, int p, int all) {
	int mx = 0;
	for (int i = 0; i < (int) g[v].size(); ++i)
		if (g[v][i] != p && !ok[g[v][i]]) {
			int res = findCenter(g[v][i], v, all);
			if (res != -1)
				return res;
			mx = max(mx, sz[g[v][i]]);
		}
	mx = max(mx, all - sz[v]);
	if (mx <= (all >> 1))
		return v;
	return -1;
}

void DFS(int v, int p) {
	fullSize(v, p);
	int center = findCenter(v, p, sz[v]);
	parC[center] = p;
	ok[center] = true;
	for (int i = 0; i < (int) g[center].size(); ++i)
		if (!ok[g[center][i]])
			DFS(g[center][i], center);
}

int LCA(int u, int v) {
	if (dep[v] < dep[u])
		swap(u, v);
	int log = 0;
	while ((1 << log) <= dep[v])
		++log;
	--log;
	for (int i = log; i >= 0; --i)
		if (dep[v] - (1 << i) >= dep[u])
			v = dp[v][i];
	if (v == u)
		return u;
	for (int i = log; i >= 0; --i)
		if (dp[u][i] != -1 && dp[v][i] != -1 && dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	return par[u];
}

inline int dist(int u, int v) {
	return dep[u] + dep[v] - (dep[LCA(u, v)] << 1);
}

void update(int v) {
	if (!col[v]) {
		for (int u = v; u != -1; u = parC[u])
			at[u].insert(make_pair(dist(v, u), v));
		col[v] = true;
	} else {
		for (int u = v; u != -1; u = parC[u])
			at[u].erase(make_pair(dist(v, u), v));
		col[v] = false;
	}
}

int query(int v) {
	int res = 2e9;
	for (int u = v; u != -1; u = parC[u]) {
		if (!at[u].empty())
			res = min(res, dist(v, u) + at[u].begin()->first);
	}
	if (res == 2e9)
		res = -1;
	return res;
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	par[0] = -1;
	DFS(0);
	DFS(0, -1);
	for (int i = 0; i < n; ++i)
		dp[i][0] = par[i];
	for (int j = 1; (1 << j) < n; ++j)
		for (int i = 0; i < n; ++i)
			if (dp[i][j - 1] != -1)
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			else
				dp[i][j] = -1;
	int q;
	scanf("%d", &q);
	while (q--) {
		int type, v;
		scanf("%d%d", &type, &v);
		--v;
		if (type == 0)
			update(v);
		else
			printf("%d\n", query(v));
	}
	return 0;
}
