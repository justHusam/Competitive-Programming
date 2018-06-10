#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 120;
vector<int> g[N];
int match[N], vis[N], vs;

bool DFS(int v) {
	vis[v] = vs;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (match[u] == -1 || (vis[match[u]] != vs && DFS(match[u]))) {
			match[u] = v;
			return true;
		}
	}
	return false;
}

int maxMatching() {
	int res = 0;
	for (int i = 0; i < N; ++i) {
		++vs;
		if (DFS(i))
			++res;
	}
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		for (int i = 0; i < N; ++i)
			g[i].clear(), match[i] = -1;
		int m;
		scanf("%d", &m);
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
		}
		printf("%d\n", maxMatching());
	}
	return 0;
}
