#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) && n != 0) {
		vector<vector<bool> > g(n, vector<bool>(n, 0));
		int x, y;
		while (scanf("%d", &x) && x != 0) {
			--x;
			while (scanf("%d", &y) && y != 0) {
				--y;
				g[x][y] = true;
			}
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] = g[i][j] | (g[i][k] & g[k][j]);
		int q;
		scanf("%d", &q);
		while (q-- != 0) {
			scanf("%d", &x);
			--x;
			vector<int> res;
			for (int i = 0; i < n; ++i)
				if (!g[x][i])
					res.push_back(i + 1);
			printf("%d", res.size());
			for (size_t i = 0; i < res.size(); ++i)
				printf(" %d", res[i]);
			putchar('\n');
		}
	}
	return 0;
}
