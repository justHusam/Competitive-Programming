#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int x, y, c;
	state(int x, int y, int c) :
			x(x), y(y), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

const int N = 201;
int n, m, v[N][N], cost[N][N];
char g[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
bool vis[N][N];

int Dijkstra(int sx, int sy, int ex, int ey) {
	priority_queue<state> qu;
	cost[sx][sy] = 0;
	qu.push(state(sx, sy, 0));
	while (!qu.empty()) {
		state e = qu.top();
		qu.pop();
		if (e.x == ex && e.y == ey)
			return e.c;
		if (vis[e.x][e.y])
			continue;
		vis[e.x][e.y] = true;
		for (int i = 0; i < 4; ++i) {
			int tx = e.x + dx[i];
			int ty = e.y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty])
				continue;
			int c = e.c + 1;
			if (g[tx][ty] == '#' && e.c < v[tx][ty])
				c += v[tx][ty] - e.c - 1;
			if (c < cost[tx][ty]) {
				cost[tx][ty] = c;
				qu.push(state(tx, ty, c));
			}
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf("%d", &v[i][j]);
				cost[i][j] = 2e9;
				vis[i][j] = false;
			}
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", Dijkstra(x1, y1, x2, y2));
	}
	return 0;
}
