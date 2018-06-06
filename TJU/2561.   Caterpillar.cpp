#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300;
int n, m, low[N], idx[N], id, mx, at, par[N];
vector<int> g[N], all;
vector<pair<int, int> > br;
bool E[N];

void DFS(int v, int p) {
	low[v] = idx[v] = id++;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (idx[u] == -1) {
			DFS(u, v);
			if (low[u] > idx[v])
				br.push_back(make_pair(v, u));
		} else if (u != p)
			low[v] = min(low[v], idx[u]);
	}
}

void DFS(int v, int p, int w) {
	if (w > mx) {
		mx = w;
		at = v;
	}
	par[v] = p;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (u == p)
			continue;
		DFS(u, v, w + 1);
	}
}

bool check() {
	for (size_t i = 0; i < all.size(); ++i)
		for (size_t j = 0; j < g[all[i]].size(); ++j) {
			int u = g[all[i]][j];
			if (!E[u] && g[u].size() > 1)
				return false;
		}
	return true;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			idx[i] = -1;
			E[i] = false;
		}
		scanf("%d", &m);
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		id = 0;
		br.clear();
		DFS(0, -1);
		if ((int) br.size() != n - 1) {
			printf("Graph %d is not a caterpillar.\n", cas++);
			continue;
		}
		mx = -1;
		DFS(0, -1, 0);
		mx = -1;
		DFS(at, -1, 0);
		all.clear();
		while (at != -1) {
			all.push_back(at);
			E[at] = true;
			at = par[at];
		}
		if (check())
			printf("Graph %d is a caterpillar.\n", cas++);
		else
			printf("Graph %d is not a caterpillar.\n", cas++);
	}
	return 0;
}
