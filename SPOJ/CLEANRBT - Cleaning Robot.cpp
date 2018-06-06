#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

int W, H, arr[22][22], cnt, strM;
char grid[22][22];
pair<int, int> strP;

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < H && y < W && grid[x][y] != 'x';
}

int BFS(pair<int, int> str, int dir) {
	queue<pair<pair<int, int>, int> > qu;
	int tx, ty, siz, lev = 1, mask;
	bool vis[22][22][1 << 10] = { };
	qu.push(make_pair(str, dir));
	vis[str.first][str.second][dir] = true;
	while (!qu.empty()) {
		int siz = qu.size();
		while (siz-- != 0) {
			pair<pair<int, int>, int> temp = qu.front();
			qu.pop();
			for (int i = 0; i < 4; ++i) {
				int mask = temp.second;
				int tx = temp.first.first + dx[i];
				int ty = temp.first.second + dy[i];
				if (check(tx, ty)) {
					if (grid[tx][ty] == '*')
						mask &= ~(1 << arr[tx][ty]);
					if (mask == 0)
						return lev;
					if (vis[tx][ty][mask])
						continue;
					vis[tx][ty][mask] = true;
					qu.push(make_pair(make_pair(tx, ty), mask));
				}
			}
		}
		lev++;
	}
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d %d", &W, &H) && make_pair(W, H) != make_pair(0, 0)) {
		int strM = 0, cnt = 0;
		for (int i = 0; i < H; ++i) {
			getchar();
			for (int j = 0; j < W; ++j) {
				grid[i][j] = getchar();
				if (grid[i][j] == 'o')
					strP = make_pair(i, j);
				if (grid[i][j] == '*') {
					arr[i][j] = cnt++;
					strM = (strM << 1) | 1;
				}
			}
		}
		printf("%d\n", BFS(strP, strM));
	}
	return 0;
}
