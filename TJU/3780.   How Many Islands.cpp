#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, m, g[55][55];
bool vis[55][55];

inline void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= m || ty >= n || vis[tx][ty] || !g[tx][ty])
			continue;
		dfs(tx, ty);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		memset(vis, false, sizeof vis);
		int res = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][j] && !vis[i][j]) {
					++res;
					dfs(i, j);
				}
		printf("%d\n", res);
	}
	return 0;
}
