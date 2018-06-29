#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> g[N];
int with[N], n, m;
bool vis[N];

int DFS(int v) {
	vis[v] = true;
	int res = with[v];
	for (size_t i = 0; i < g[v].size(); ++i)
		if (!vis[g[v][i]])
			res += DFS(g[v][i]);
	return res;
}

bool check() {
	for (int i = 0; i < n; ++i)
		if (!vis[i] && DFS(i) < 0)
			return false;
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", with + i);
			vis[i] = false;
			g[i].clear();
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (check())
			puts("POSSIBLE");
		else
			puts("IMPOSSIBLE");
	}
	return 0;
}
