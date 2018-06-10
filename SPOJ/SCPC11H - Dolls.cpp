#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500;
int n, w[N], l[N], h[N], vis[N], vs, match[N];
vector<int> g[N];

bool DFS(int v) {
	vis[v] = vs;
	for (int i = 0; i < (int) g[v].size(); ++i) {
		int u = match[g[v][i]];
		if (u == -1 || (vis[u] != vs && DFS(u))) {
			match[g[v][i]] = v;
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			match[i] = -1;
		}
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d", &w[i], &l[i], &h[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (w[i] < w[j] && l[i] < l[j] && h[i] < h[j])
					g[i].push_back(j);
		int res = 0;
		for (int i = 0; i < n; ++i) {
			++vs;
			if (DFS(i))
				++res;
		}
		printf("%d\n", n - res);
	}
	return 0;
}
