#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
vector<int> g[N], G[N], st;
int n, low[N], idx[N], comp[N], cnt, id, sz[N], deg[N];
bool in[N];

void DFS(int v) {
	low[v] = idx[v] = ++id;
	in[v] = true;
	st.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!idx[u]) {
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
			comp[n] = cnt;
			++sz[cnt];
		} while (n != v);
		++cnt;
	}
}

int main() {
//	freopen("a", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			deg[i] = sz[i] = idx[i] = 0;
		}
		for (int i = 0, x, j; i < n; ++i) {
			scanf("%d", &x);
			while (x-- != 0) {
				scanf("%d", &j);
				--j;
				g[j].push_back(i);
			}
		}
		id = cnt = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i);
		for (int i = 0; i < n; ++i)
			for (size_t j = 0; j < g[i].size(); ++j)
				if (comp[i] != comp[g[i][j]])
					G[comp[i]].push_back(comp[g[i][j]]);
		for (int i = 0; i < cnt; ++i) {
			sort(G[i].begin(), G[i].end());
			G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
			for (size_t j = 0; j < G[i].size(); ++j)
				++deg[G[i][j]];
		}
		int root, can = 0;
		for (int i = 0; i < cnt && can <= 1; ++i)
			if (deg[i] == 0) {
				++can;
				root = i;
			}
		int res = 0;
		if (can == 1)
			res += sz[root];
		printf("%d\n", res);
	}
	return 0;
}
