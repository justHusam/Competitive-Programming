#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
int a[N], last;
bool vis[N];

int DFS(int v) {
	vis[v] = true;
	last = v;
	int n = 0, mx = -1;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (a[u] > mx && !vis[u])
			mx = a[u], n = u;
	}
	if (mx == -1)
		return 0;
	return DFS(n) + mx;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			g[i].clear();
			vis[i] = false;
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
		}
		int res = DFS(0);
		printf("Case %d: %d %d\n", k++, res, last);
	}
	return 0;
}
