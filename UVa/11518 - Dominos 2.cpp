#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e4;
vector<int> g[N];
bool vis[N];

int DFS(int v) {
	vis[v] = true;
	int res = 1;
	for (size_t i = 0; i < g[v].size(); ++i)
		if (!vis[g[v][i]])
			res += DFS(g[v][i]);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, l;
		scanf("%d%d%d", &n, &m, &l);
		for (int i = 0; i < n; ++i)
			g[i].clear(), vis[i] = false;
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
		}
		int res = 0;
		while (l-- != 0) {
			int src;
			scanf("%d", &src);
			--src;
			if (!vis[src])
				res += DFS(src);
		}
		printf("%d\n", res);
	}
	return 0;
}
