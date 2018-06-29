#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3, oo = 1e9;
int n, m, low[N], idx[N], u[N << 1], v[N << 1], c[N << 1], dfs, at[N], comp, head[N], cost[N], size[N];
vector<pair<int, int> > g[N];
vector<int> G[N], st;
bool in[N], vis[N];
queue<int> qu;
vector<vector<int> > e;

void DFS(int v) {
	low[v] = idx[v] = ++dfs;
	in[v] = true;
	st.push_back(v);
	for (int i = 0; i < (int) g[v].size(); ++i) {
		int u = g[v][i].first;
		if (idx[u] == -1) {
			DFS(u);
			low[v] = min(low[v], low[u]);
		} else if (in[u])
			low[v] = min(low[v], low[u]);
	}
	if (low[v] == idx[v]) {
		int n;
		do {
			n = st.back();
			st.pop_back();
			in[n] = false;
			at[n] = comp;
			++size[comp];
		} while (n != v);
		head[comp++] = v;
	}
}

void BellmanFord(int src) {
	cost[head[src]] = 0;
	bool ok = true;
	for (int it = 1; it < size[src] && ok; ++it) {
		ok = false;
		for (size_t i = 0; i < e[src].size(); ++i) {
			int a = u[e[src][i]], b = v[e[src][i]];
			if (cost[a] < oo && cost[a] + c[e[src][i]] < cost[b]) {
				ok = true;
				cost[b] = cost[a] + c[e[src][i]];
			}
		}
	}
	for (size_t i = 0; i < e[src].size(); ++i) {
		int a = u[e[src][i]], b = v[e[src][i]];
		if (cost[a] < oo && cost[a] + c[e[src][i]] < cost[b])
			vis[a] = true;
	}
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			idx[i] = -1;
			cost[i] = oo;
			size[i] = 0;
			vis[i] = false;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &u[i], &v[i], &c[i]);
			g[u[i]].push_back(make_pair(v[i], i));
			G[v[i]].push_back(u[i]);
		}
		dfs = comp = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == -1)
				DFS(i);
		e.clear();
		e.resize(comp);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < (int) g[i].size(); ++j)
				if (at[i] == at[g[i][j].first])
					e[at[i]].push_back(g[i][j].second);
		for (int i = 0; i < comp; ++i)
			BellmanFord(i);
		for (int i = 0; i < n; ++i)
			if (vis[i])
				qu.push(i);
		while (!qu.empty()) {
			int v = qu.front();
			qu.pop();
			for (int i = 0; i < (int) G[v].size(); ++i)
				if (!vis[G[v][i]]) {
					vis[G[v][i]] = true;
					qu.push(G[v][i]);
				}
		}
		bool ok = false;
		for (int i = 0; i < n && !ok; ++i)
			ok |= vis[i];
		printf("Case %d:", cas++);
		if (!ok)
			puts(" impossible");
		else {
			for (int i = 0; i < n; ++i)
				if (vis[i])
					printf(" %d", i);
			puts("");
		}
	}
	return 0;
}
