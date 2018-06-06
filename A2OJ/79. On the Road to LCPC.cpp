#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, q, E[N << 1], L[N << 1], H[N], idx, dp[N << 1][19];
vector<int> g[N];

void DFS(int v, int p, int d) {
	H[v] = idx;
	E[idx] = v;
	L[idx++] = d;
	for (int i = 0; i < (int) g[v].size(); ++i)
		if (g[v][i] != p) {
			DFS(g[v][i], v, d + 1);
			E[idx] = v;
			L[idx++] = d;
		}
}

inline int LCA(int a, int b) {
	if (b < a)
		swap(a, b);
	int log = 0;
	while ((1 << log) <= b - a + 1)
		++log;
	--log;
	if (L[dp[a][log]] < L[dp[b - (1 << log) + 1][log]])
		return E[dp[a][log]];
	return E[dp[b - (1 << log) + 1][log]];
}

int main(int argc, char **argv) {
	int T, cas = 1;
	scanf("%d", &T);
	while (T-- != 0) {
		printf("Case %d:\n", cas++);
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		idx = 0;
		DFS(0, -1, 0);
		n <<= 1;
		for (int i = 0; i < n; ++i)
			dp[i][0] = i;
		for (int j = 1; (1 << j) <= n; ++j)
			for (int i = 0; i + (1 << j) <= n; ++i)
				if (L[dp[i][j - 1]] < L[dp[i + (1 << (j - 1))][j - 1]])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
		while (q-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			int lca = LCA(H[u], H[v]);
			int len = L[H[u]] + L[H[v]] - (L[H[lca]] << 1);
			printf("%d\n", len);
		}
	}
	return 0;
}
