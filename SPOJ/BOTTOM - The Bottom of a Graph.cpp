#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e3;
int n, m, low[N], idx[N], comp[N], id, cnt;
vector<int> g[N], G[N], st;
bool in[N], vis[N];

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
			G[cnt].push_back(n);
		} while (n != v);
		++cnt;
	}
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			idx[i] = 0;
			vis[i] = false;
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
			if (!idx[i])
				DFS(i);
		for (int i = 0; i < n; ++i)
			for (size_t j = 0; j < g[i].size(); ++j)
				if (comp[i] != comp[g[i][j]])
					vis[comp[i]] = true;
		vector<int> sol;
		for (int i = 0; i < cnt; ++i)
			if (!vis[i])
				for (size_t j = 0; j < G[i].size(); ++j)
					sol.push_back(G[i][j] + 1);
		sort(sol.begin(), sol.end());
		for (size_t i = 0; i < sol.size(); ++i)
			printf("%s%d", i ? " " : "", sol[i]);
		puts("");
	}
	return 0;
}
