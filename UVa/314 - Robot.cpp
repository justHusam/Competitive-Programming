#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 2, -2, 1, -1, 1, -1 }, dy[] = { 2, -2, 0, 0, 1, -1, -1, 1 };
int dr[4][2] = { { 2, 3 }, { 2, 3 }, { 0, 1 }, { 0, 1 } };

int N, M;
int g[105][105];
pair<int, int> str, tar;
char dir[11];
bool vis[105][105][5];

bool check(int x, int y) {
	int r = N * 2 - 1, c = M * 2 - 1;
	if (x < 1 || y < 1 || x > r || y > c)
		return false;
	for (int i = 4; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx > r || ty > c)
			continue;
		if (g[tx][ty])
			return false;
	}
	return true;
}

int getDir(string dir) {

	if (dir == "east")
		return 0;
	if (dir == "west")
		return 1;
	if (dir == "south")
		return 2;
	if (dir == "north")
		return 3;
	return -1;
}

int BFS(pair<int, int> src, pair<int, int> dest) {
	queue<pair<int, pair<int, int>> > qu;
	int cost = 1, dir = getDir(::dir);
	if (src == dest)
		return 0;
	memset(vis, false, sizeof vis);
	qu.push( { dir, src });
	vis[src.first][src.second][dir] = true;
	while (!qu.empty()) {
		int size = qu.size();
		while (size-- != 0) {
			pair<int, pair<int, int> > e = qu.front();
			qu.pop();
			for (int i = 0; i < 2; ++i) {
				if (vis[e.second.first][e.second.second][dr[e.first][i]])
					continue;
				qu.push( { dr[e.first][i], e.second });
				vis[e.second.first][e.second.second][dr[e.first][i]] = true;
			}
			for (int i = 1; i < 4; ++i) {
				int tx = e.second.first + (dx[e.first] * i);
				int ty = e.second.second + (dy[e.first] * i);
				if (!check(tx, ty))
					break;
				if (vis[tx][ty][e.first])
					continue;
				if (make_pair(tx, ty) == dest)
					return cost;
				vis[tx][ty][e.first] = true;
				qu.push( { e.first, { tx, ty } });
			}
		}
		++cost;
	}
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &N, &M) && N != 0 && M != 0) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				scanf("%d", &g[i * 2 + 1][j * 2 + 1]);
		pair<int, int> src, dest;
		scanf("%d%d%d%d", &src.first, &src.second, &dest.first, &dest.second);
		src.first <<= 1;
		src.second <<= 1;
		dest.first <<= 1;
		dest.second <<= 1;
		scanf("%s", dir);
		printf("%i\n", BFS(src, dest));
	}
	return 0;
}
