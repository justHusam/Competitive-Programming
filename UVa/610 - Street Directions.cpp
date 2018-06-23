#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, m, low[N], idx[N], id;
vector<int> g[N];
vector<pair<int, int> > sol;
bool br[N][N], vis[N], E[N][N];

void DFS(int v, int p) {
	low[v] = idx[v] = ++id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!idx[u]) {
			DFS(u, v);
			if (low[u] > idx[v]) {
				br[u][v] = br[v][u] = true;
				sol.push_back(make_pair(u, v));
				sol.push_back(make_pair(v, u));
			}
			low[v] = min(low[v], low[u]);
		} else if (u != p)
			low[v] = min(low[v], idx[u]);
	}
}

void build(int v, int p) {
	vis[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (br[u][v] || u == p || E[u][v])
			continue;
		E[v][u] = true;
		sol.push_back(make_pair(v, u));
		if (!vis[u])
			build(u, v);
	}
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			idx[i] = 0;
			vis[i] = false;
			for (int j = i; j < n; ++j)
				br[i][j] = br[j][i] = E[i][j] = E[j][i] = false;
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		id = 0;
		sol.clear();
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i, -1);
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				build(i, -1);
		printf("%d\n\n", cas++);
		for (size_t i = 0; i < sol.size(); ++i)
			printf("%d %d\n", sol[i].first + 1, sol[i].second + 1);
		puts("#");
	}
	return 0;
}
