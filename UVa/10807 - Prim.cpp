#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator<(const edge&e) const {
		return c < e.c;
	}
};

int n, m, p[10], best, all;
vector<edge> e;
vector<int> g[10][10];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void calc(int i, int cost, int E, int nodes, int edges) {
	if (cost >= best || m - E < n - 1)
		return;
	if (E == n - 1 && nodes == all) {
		for (int i = 0; i < n; ++i)
			p[i] = i;
		int cnt = 0, res = 0;
		for (int i = 0; i < m && cnt != n - 1; ++i) {
			if (((edges >> i) & 1) == 0)
				continue;
			int a = find(e[i].u);
			int b = find(e[i].v);
			if (a == b)
				return;
			p[a] = b;
			++cnt;
		}
		if (cnt != n - 1)
			return;
		for (int i = 0; i < n; ++i)
			p[i] = i;
		cnt = 0;
		for (int i = 0; i < m && cnt != n - 1; ++i) {
			if (((edges >> i) & 1) == 1)
				continue;
			int a = find(e[i].u);
			int b = find(e[i].v);
			if (a != b) {
				p[a] = b;
				res += e[i].c;
				++cnt;
				if (cost + res >= best)
					return;
			}
		}
		if (cnt == n - 1)
			best = cost + res;
		return;
	}
	if (i == m || E == n - 1 || nodes == all)
		return;
	calc(i + 1, cost, E, nodes, edges);
	calc(i + 1, cost + e[i].c, E + 1, nodes | (1 << e[i].u) | (1 << e[i].v), edges | (1 << i));
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		scanf("%d", &m);
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				g[i][j].clear();
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			if (v < u)
				swap(u, v);
			if (u != v)
				g[u][v].push_back(c);
		}
		if (m < 2 * n - 2) {
			puts("No way!");
			continue;
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				sort(g[i][j].begin(), g[i][j].end());
		e.clear();
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				int mn = min(2, (int) g[i][j].size());
				for (int k = 0; k < mn; ++k)
					e.push_back(edge(i, j, g[i][j][k]));
			}
		m = e.size();
		if (m < 2 * n - 2) {
			puts("No way!");
			continue;
		}
		for (int i = 0; i < n; ++i)
			p[i] = i;
		int cnt = 0;
		for (int i = 0; i < m && cnt != n - 1; ++i) {
			int a = find(e[i].u);
			int b = find(e[i].v);
			if (a != b) {
				p[a] = b;
				++cnt;
			}
		}
		if (cnt != n - 1) {
			puts("No way!");
			continue;
		}
		sort(e.begin(), e.end());
		best = 2e9;
		all = (1 << n) - 1;
		calc(0, 0, 0, 0, 0);
		if (best == 2e9)
			puts("No way!");
		else
			printf("%d\n", best);
	}
	return 0;
}
