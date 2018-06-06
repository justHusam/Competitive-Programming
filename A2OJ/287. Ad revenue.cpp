#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e4;
int low[N], idx[N], comp[N], id, cnt, v[N], vv[N], dp[N];
vector<int> g[N], G[N], st;
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
		res = max(res, calc(G[v][i]));
	res += vv[v];
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			G[i].clear();
			vv[i] = idx[i] = 0;
			dp[i] = -1;
		}
		for (int i = 0, m; i < n; ++i) {
			scanf("%d%d", &v[i], &m);
			while (m-- != 0) {
				int j;
				scanf("%d", &j);
				g[i].push_back(j);
			}
		}
		id = cnt = 0;
		for (int i = 0; i < n; ++i)
			if (!idx[i])
				DFS(i);
		for (int i = 0; i < n; ++i) {
			for (size_t j = 0; j < g[i].size(); ++j)
				if (comp[i] != comp[g[i][j]])
					G[comp[i]].push_back(comp[g[i][j]]);
			vv[comp[i]] += v[i];
		}
		int res = 0;
		for (int i = 0; i < cnt; ++i)
			res = max(res, calc(i));
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
