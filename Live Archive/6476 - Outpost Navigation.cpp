#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, w[N], g[N][N];
map<string, int> hs;
char a[10], b[10];
vector<int> E;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		E.clear();
		hs.clear();
		int at = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%s%d%s", a, &w[i], b);
			hs[a] = i;
			if (b[0] == 'y')
				E.push_back(i);
			else if (w[i] > 0 && i > 0)
				at = i;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j)
				g[i][j] = g[j][i] = 1e9;
			g[i][i] = 0;
		}
		while (m-- > 0) {
			int c;
			scanf("%s%s%d", a, b, &c);
			int u = hs[a];
			int v = hs[b];
			g[u][v] = g[v][u] = min(g[u][v], c);
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		int best = 2e9;
		for (size_t i = 0; i < E.size(); ++i) {
			if (g[0][E[i]] <= w[0])
				best = min(best, g[0][E[i]]);
			if (at != -1 && g[0][at] <= w[0]) {
				int rem = w[0] - g[0][at] + w[at];
				if (g[at][E[i]] <= rem)
					best = min(best, g[0][at] + g[at][E[i]]);
			}
		}
		if (best == 2e9)
			puts("No safe path");
		else
			printf("%d\n", best);
	}
	return 0;
}
