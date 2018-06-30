#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, y;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
char g[11][11];
bool vis[10][10];
pair<int, int> par[10][10];

int get(int o) {
	if (o == 'N')
		return 3;
	if (o == 'S')
		return 2;
	if (o == 'E')
		return 0;
	return 1;
}

pair<int, int> DFS(int x, int y, int s) {
	vis[x][y] = true;
	int i = get(g[x][y]);
	int tx = x + dx[i];
	int ty = y + dy[i];
	if (tx < 0 || ty < 0 || tx >= n || ty >= m)
		return make_pair(s + 1, -1);
	par[tx][ty] = make_pair(x, y);
	if (vis[tx][ty]) {
		int c = 1;
		for (pair<int, int> i = par[x][y]; i != make_pair(tx, ty); i = par[i.first][i.second])
			++c;
		return make_pair(s - c, c + 1);
	}
	return DFS(tx, ty, s + 1);
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &m, &y) > 0 && n + m + y != 0) {
		memset(vis, false, sizeof vis);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		--y;
		pair<int, int> res = DFS(0, y, 0);
		if (res.second == -1)
			printf("%d step(s) to exit\n", res.first);
		else
			printf("%d step(s) before a loop of %d step(s)\n", res.first, res.second);
	}
	return 0;
}
