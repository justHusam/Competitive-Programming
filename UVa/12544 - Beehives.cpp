#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500, oo = 1e9;
int n, m, cost[N], qu[N], par[N];
vector<int> g[N];

int BFS(int src) {
	for (int i = 0; i < n; ++i)
		cost[i] = oo;
	int l = 0, r = 0, res = oo;
	qu[r++] = src;
	cost[src] = 0;
	par[src] = -1;
	while (l < r) {
		int v = qu[l++];
		for (size_t i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (cost[u] == oo) {
				cost[u] = cost[v] + 1;
				par[u] = v;
				qu[r++] = u;
			} else if (u != par[v])
				res = min(res, cost[u] + cost[v] + 1);
		}
	}
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		printf("Case %d: ", cas++);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res = oo;
		for (int i = 0; i < n; ++i)
			res = min(res, BFS(i));
		if (res == oo)
			puts("impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
