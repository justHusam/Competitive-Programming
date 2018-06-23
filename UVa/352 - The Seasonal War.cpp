#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 26;
char g[N][N];
int n;
bool vis[N][N];
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 }, dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void DFS(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < n && ty < n && g[tx][ty] == '1' && !vis[tx][ty])
			DFS(tx, ty);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		memset(vis, false, sizeof vis);
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][j] == '1' && !vis[i][j])
					++res, DFS(i, j);
		static int k = 1;
		printf("Image number %d contains %d war eagles.\n", k++, res);
	}
	return 0;
}
