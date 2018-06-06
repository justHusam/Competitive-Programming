#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3;
int low[N], idx[N], in[N], id, cnt, comp[N], vis[N], bfsID;
vector<int> g[N], st, G[N];

void DFS(int v) {
	st.push_back(v);
	in[v] = 1;
	low[v] = idx[v] = ++id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!idx[u]) {
			DFS(u);
			low[v] = min(low[v], low[u]);
			continue;
		}
		if (in[u])
			low[v] = min(low[v], low[u]);
	}
	if (low[v] == idx[v]) {
		int n;
		do {
			n = st.back();
			st.pop_back();
			in[n] = 0;
			comp[n] = cnt;
		} while (n != v);
		++cnt;
	}
}

bool BFS(int str, int tar) {
	if (str == tar)
		return true;
	++bfsID;
	queue<int> qu;
	qu.push(str);
	vis[str] = bfsID;
	while (qu.size()) {
		const int fr = qu.front();
		qu.pop();
		for (size_t i = 0; i < G[fr].size(); ++i) {
			int u = G[fr][i];
			if (u == tar)
				return true;
			if (vis[u] == bfsID)
				continue;
			vis[u] = bfsID;
			qu.push(u);
		}
	}
	return false;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear(), in[i] = low[i] = idx[i] = 0;
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
		for (int i = 0; i < cnt; ++i)
			G[i].clear();
		for (int i = 0; i < n; ++i)
			for (size_t j = 0; j < g[i].size(); ++j)
				G[comp[i]].push_back(comp[g[i][j]]);
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", k++);
		while (q-- != 0) {
			int str, tar;
			scanf("%d%d", &str, &tar);
			--str;
			--tar;
			if (BFS(comp[str], comp[tar]))
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
