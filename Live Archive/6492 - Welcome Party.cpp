#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 26;
int n, vis[N], match[N], vs;
vector<int> g[N];
char a[111], b[111];

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
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < N; ++i)
			g[i].clear(), match[i] = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%s%s", a, b);
			g[a[0] - 'A'].push_back(b[0] - 'A');
		}
		printf("%d\n", maxMatching());
	}
	return 0;
}
