#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
int n, q, in[N], par[N], dep[N], dp[N][14];
vector<int> g[N];

void DFS(int v) {
	for (int i = 0; i < g[v].size(); ++i)
		if (g[v][i] != par[v]) {
			par[g[v][i]] = v;
			dep[g[v][i]] = dep[v] + 1;
			DFS(g[v][i]);
		}
}

bool check(int a, int b) {
	if (b == a || dep[b] < dep[a])
		return false;
	int log = 0;
	while ((1 << log) <= dep[b])
		++log;
	--log;
	for (int i = log; i >= 0; --i)
		if (dep[b] - (1 << i) >= dep[a])
			b = dp[b][i];
	return b == a;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &v, &u);
			g[u].push_back(v);
		}
		par[0] = -1;
		dep[0] = 0;
		DFS(0);
		for (int i = 0; i < n; ++i)
			dp[i][0] = par[i];
		for (int j = 1; (1 << j) < n; ++j)
			for (int i = 0; i < n; ++i)
				if (dp[i][j - 1] != -1)
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
				else
					dp[i][j] = -1;
		scanf("%d", &q);
		while (q-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (check(a, b))
				puts("Yes");
			else
				puts("No");
		}
		puts("");
	}
	return 0;
}
