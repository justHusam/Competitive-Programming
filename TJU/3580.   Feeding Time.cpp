#include <bits/stdc++.h>
using namespace std;

const int N = 751;
int n, m;
char g[N][N];
bool vis[N][N];
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 }, dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
queue<pair<int, int> > qu;

int BFS(int x, int y) {
	qu.push(make_pair(x, y));
	vis[x][y] = true;
	int res = 0;
	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		++res;
		for (int i = 0; i < 8; ++i) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || g[tx][ty] == '*')
				continue;
			vis[tx][ty] = true;
			qu.push(make_pair(tx, ty));
		}
	}
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", g[i]);
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!vis[i][j] && g[i][j] == '.')
				res = max(res, BFS(i, j));
	printf("%d\n", res);
	return 0;
}
