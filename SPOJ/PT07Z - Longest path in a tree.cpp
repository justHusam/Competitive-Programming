#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> g[N];
int mxLen, at;

void DFS(int v, int par, int len) {
	for (size_t i = 0; i < g[v].size(); i++)
		if (g[v][i] != par)
			DFS(g[v][i], v, len + 1);
	if (len > mxLen) {
		mxLen = len;
		at = v;
	}
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%i", &n) > 0) {
		int u, v;
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		mxLen = -1;
		DFS(0, -1, 0);
		DFS(at, -1, 0);
		printf("%d\n", mxLen);
	}
	return 0;
}
