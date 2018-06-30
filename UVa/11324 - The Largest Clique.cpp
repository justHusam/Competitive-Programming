#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, m, low[N], idx[N], sz[N], dp[N], id, cnt, comp[N];
vector<int> G[N], g[N], st;
bool in[N];

void DFS(int v) {
	low[v] = idx[v] = id++;
	in[v] = true;
	st.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
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
			++sz[cnt];
			comp[n] = cnt;
		} while (n != v);
		++cnt;
	}
}

int calc(int v) {
	int &res = dp[v];
	if (res != -1)
		return res;
	res = 0;
	for (size_t i = 0; i < G[v].size(); ++i)
		res = max(res, calc(G[v][i]) + sz[G[v][i]]);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			idx[i] = dp[i] = -1;
			sz[i] = 0;
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
		}
		id = cnt = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == -1)
				DFS(i);
		for (int i = 0; i < n; ++i)
			for (size_t j = 0; j < g[i].size(); ++j)
				if (comp[i] != comp[g[i][j]])
					G[comp[i]].push_back(comp[g[i][j]]);
		for (int i = 0; i < cnt; ++i) {
			sort(G[i].begin(), G[i].end());
			G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
		}
		int res = 0;
		for (int i = 0; i < cnt; ++i)
			res = max(res, calc(i) + sz[i]);
		printf("%d\n", res);
	}
	return 0;
}
