#include <bits/stdc++.h>
using namespace std;

char g[27][27];
bool vis[27][27];
priority_queue<pair<int, pair<int, int> >> qu;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int W, H, cost[27][27];

inline bool check(int a, int b) {
	return a >= 0 && b >= 0 && a < H && b < W && !vis[a][b] && g[a][b] != 'X';
}

int Dijkstra(pair<int, int> str, pair<int, int> ed) {
	memset(cost, 0x3f, sizeof cost);
	cost[str.first][str.second] = 0;
	qu.push(make_pair(0, make_pair(str.first, str.second)));
	while (!qu.empty()) {
		pair<int, pair<int, int> > e = qu.top();
		qu.pop();
		if (vis[e.second.first][e.second.second])
			continue;
		vis[e.second.first][e.second.second] = true;
		for (int i = 0; i < 4; ++i) {
			int tx = e.second.first + dx[i];
			int ty = e.second.second + dy[i];
			if (check(tx, ty)) {
				if (g[tx][ty] == 'D') {
					if (cost[e.second.first][e.second.second] < cost[tx][ty])
						cost[tx][ty] = cost[e.second.first][e.second.second];
				} else {
					int cst = cost[e.second.first][e.second.second] + (g[tx][ty] - '0');
					if (cst < cost[tx][ty]) {
						cost[tx][ty] = cst;
						qu.push(make_pair(-cst, make_pair(tx, ty)));
					}
				}
			}
		}
	}
	return cost[ed.first][ed.second];
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &W, &H) && W + H > 0) {
		memset(vis, false, sizeof vis);
		pair<int, int> src, dest;
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == 'S')
					src.first = i, src.second = j;
				else if (g[i][j] == 'D')
					dest.first = i, dest.second = j;
			}
		printf("%d\n", Dijkstra(src, dest));
	}
	return 0;
}

