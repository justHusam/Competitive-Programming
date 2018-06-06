#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
vector<int> g[N], G[N], hs[N], st;
int n, m, low[N], idx[N], id, cnt, comp[N], dp[N];
bool in[N];
vector<pair<int, int> > E;

void DFS(int v) {
	in[v] = true;
	low[v] = idx[v] = ++id;
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
			hs[cnt].push_back(n);
			comp[n] = cnt;
		} while (n != v);
		++cnt;
	}
}

int calc(int v) {
	int &res = dp[v];
	if (res != -1)
		return res;
	res = 1;
	for (size_t i = 0; i < G[v].size(); ++i)
		res += calc(G[v][i]);
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	while (m-- != 0) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		E.push_back(make_pair(v, u));
	}
	for (int i = 0; i < n; ++i)
		if (idx[i] == 0)
			DFS(i);
	for (size_t i = 0; i < E.size(); ++i)
		if (comp[E[i].first] != comp[E[i].second])
			G[comp[E[i].first]].push_back(comp[E[i].second]);
	for (int i = 0; i < cnt; ++i) {
		sort(G[i].begin(), G[i].end());
		G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
	}
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; ++i)
		calc(i);
	vector<int> sol;
	for (int i = 0; i < cnt; ++i)
		if (dp[i] == cnt)
			for (size_t j = 0; j < hs[i].size(); ++j)
				sol.push_back(hs[i][j] + 1);
	sort(sol.begin(), sol.end());
	printf("%d\n", (int) sol.size());
	for (size_t i = 0; i < sol.size(); ++i)
		printf("%s%d", i ? " " : "", sol[i]);
	puts("");
	return 0;
}
