#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50, oo = 1e9;
int n, g[N][N], E[N][N], res[N][N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf("%d", &g[i][j]);
				if (i == j)
					g[i][j] = 0;
				else if (g[i][j] == -1)
					g[i][j] = oo;
				E[i][j] = g[i][j];
			}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		memset(res, 0, sizeof res);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j || E[i][j] == oo) {
					res[i][j] = -1;
					continue;
				}
				for (int s = 0; s < n; ++s)
					for (int t = s + 1; t < n; ++t) {
						if (g[s][t] != oo && g[s][i] + E[i][j] + g[j][t] == g[s][t])
							++res[i][j];
						if (g[t][s] != oo && g[t][i] + E[i][j] + g[j][s] == g[t][s])
							++res[i][j];
					}
			}
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < n; ++j)
				printf("%s%d", j ? " " : "", res[i][j]);
	}
	return 0;
}
