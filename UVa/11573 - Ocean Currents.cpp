#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
int g[N][N], n, m, cost[N][N];
bool vis[N][N];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int BFS(pair<int, int> src, pair<int, int> dest) {
	if (src == dest)
		return 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			vis[i][j] = false;
			cost[i][j] = 2e9;
		}
	deque<pair<int, int> > qu;
	qu.push_back(src);
	cost[src.first][src.second] = 0;
	while (!qu.empty()) {
		pair<int, int> e = qu.front();
		qu.pop_front();
		if (vis[e.first][e.second])
			continue;
		vis[e.first][e.second] = true;
		if (e == dest)
			return cost[e.first][e.second];
		for (int i = 0; i < 8; ++i) {
			int tx = e.first + dx[i];
			int ty = e.second + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty])
				continue;
			if (g[e.first][e.second] == i && cost[e.first][e.second] < cost[tx][ty]) {
				qu.push_front(make_pair(tx, ty));
				cost[tx][ty] = cost[e.first][e.second];
			} else if (g[e.first][e.second] != i && cost[e.first][e.second] + 1 < cost[tx][ty]) {
				qu.push_back(make_pair(tx, ty));
				cost[tx][ty] = cost[e.first][e.second] + 1;
			}
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		getchar();
		for (int j = 0; j < m; ++j)
			g[i][j] = getchar() - '0';
	}
	int q;
	scanf("%d", &q);
	while (q-- != 0) {
		int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		--x;
		--y;
		--xx;
		--yy;
		printf("%d\n", BFS(make_pair(x, y), make_pair(xx, yy)));
	}
	return 0;
}
