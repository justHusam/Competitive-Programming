#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, id;
vector<vector<int> > g;
vector<int> low, idx;
vector<pair<int, int> > br;

void DFS(int v, int p) {
	low[v] = idx[v] = ++id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (idx[u] == 0) {
			DFS(u, v);
			if (low[u] > idx[v])
				br.push_back(make_pair(min(u, v), max(u, v)));
			low[v] = min(low[v], low[u]);
		} else if (u != p)
			low[v] = min(low[v], idx[u]);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		g.clear();
		g.resize(n);
		for (int i = 0; i < n; ++i) {
			int u, v, k;
			scanf("%d (%d)", &u, &k);
			while (k-- != 0) {
				scanf("%d", &v);
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		low.clear();
		idx.clear();
		low.resize(n);
		idx.resize(n);
		id = 0;
		br.clear();
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i, -1);
		sort(br.begin(), br.end());
		printf("%d critical links\n", (int) br.size());
		for (size_t i = 0; i < br.size(); ++i)
			printf("%d - %d\n", br[i].first, br[i].second);
		puts("");
	}
	return 0;
}
