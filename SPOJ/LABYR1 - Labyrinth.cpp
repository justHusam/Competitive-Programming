#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
pair<int, int> ans, fst;
char g[1010][1010];
bool vis[1010][1010];
int C, R, len;

void DFS(int x, int y, int cnt) {
	vis[x][y] = true;
	for (int a = 0; a < 4; ++a) {
		int nx = x + dx[a];
		int ny = y + dy[a];
		if (nx >= 0 && ny >= 0 && nx < R && ny < C && g[nx][ny] == '.' && !vis[nx][ny])
			DFS(nx, ny, cnt + 1);
	}
	if (cnt > len) {
		len = cnt;
		ans.first = x, ans.second = y;
	}
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		len = 0;
		bool flag = true;
		scanf("%d %d", &C, &R);
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == '.' && flag) {
					flag = false;
					fst.first = i, fst.second = j;
				}
			}
		}
		memset(vis, false, sizeof vis);
		DFS(fst.first, fst.second, 0);
		memset(vis, false, sizeof vis);
		DFS(ans.first, ans.second, 0);
		printf("Maximum rope length is %d.\n", len);
	}
	return 0;
}
