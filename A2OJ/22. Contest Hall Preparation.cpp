#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int> > g(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		bool vis[102] = { };
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == -1 || vis[g[i][j]])
					continue;
				for (int k = 0; k < 8; ++k) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if (tx >= 0 && ty >= 0 && tx < n && ty < m && g[i][j] == g[tx][ty]) {
						++res;
						vis[g[i][j]] = true;
						break;
					}
				}
			}
		printf("%d\n", res);
	}
	return 0;
}
