#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, m, bs[N];
vector<int> g[N], at;
bool E[N][N], vis[N];
vector<pair<int, int> > w;

void DFS(int v) {
	vis[v] = true;
	at.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (vis[u])
			continue;
		DFS(u);
	}
}

void DFS(int v, int no) {
	bs[v] = true;
	at.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (bs[u] || u == no)
			continue;
		DFS(u, no);
	}
}

bool check() {
	bool ok = true;
	for (size_t i = 0; i < at.size() && ok; ++i)
		for (size_t j = i + 1; j < at.size() && ok; ++j)
			ok &= E[at[i]][at[j]];
	return ok;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			bs[i] = vis[i] = false;
			for (int j = i; j < n; ++j)
				E[i][j] = E[j][i] = false;
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
			E[u][v] = E[v][u] = true;
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
			if (!vis[i]) {
				at.clear();
				DFS(i);
				if (at.size() & 1)
					continue;
				w.clear();
				for (size_t i = 0; i < at.size(); ++i)
					w.push_back(make_pair(g[at[i]].size(), at[i]));
				sort(w.rbegin(), w.rend());
				bool ok = w[0].first == w[1].first;
				for (size_t i = 2; i < w.size() && ok; ++i)
					ok &= w[i].first + 1 == w[0].first;
				if (!ok)
					continue;
				int sz = at.size();
				at.clear();
				DFS(w[0].second, w[1].second);
				if ((int) at.size() * 2 != sz || !check())
					continue;
				at.clear();
				DFS(w[1].second, w[0].second);
				if ((int) at.size() * 2 != sz || !check())
					continue;
				++res;
			}
		printf("Case #%d: %d\n", cas++, res);
	}
	return 0;
}
