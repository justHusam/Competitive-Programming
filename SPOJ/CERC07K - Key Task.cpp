#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

struct state {
	int x, y;
	bitset<4> msk;
	state(int x, int y, bitset<4> msk) :
			x(x), y(y), msk(msk) {
	}
};

pair<char, int> arr[4] = { { 'B', 0 }, { 'Y', 1 }, { 'R', 2 }, { 'G', 3 } };

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) && n != 0) {
		vector<vector<char> > g(n, vector<char>(m));
		int sx, sy;
		for (int i = 0; i < n; ++i) {
			getchar();
			for (int j = 0; j < m; ++j) {
				g[i][j] = getchar();
				if (g[i][j] == '*')
					sx = i, sy = j;
			}
		}
		getchar();
		bool vis[101][101][1 << 4] = { };
		queue<state> qu;
		bitset<4> bs;
		bs.reset();
		qu.push(state(sx, sy, bs));
		vis[sx][sy][bs.to_ulong()] = true;
		int res = -1, lev = 1;
		while (!qu.empty()) {
			int siz = qu.size();
			while (siz-- != 0) {
				const state t = qu.front();
				qu.pop();
				for (int i = 0; i < 4; ++i) {
					int tx = t.x + dx[i];
					int ty = t.y + dy[i];
					if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] == '#')
						continue;
					if (g[tx][ty] == 'X') {
						res = lev;
						break;
					}
					if (g[tx][ty] == '.' || g[tx][ty] == '*') {
						if (!vis[tx][ty][t.msk.to_ulong()]) {
							vis[tx][ty][t.msk.to_ulong()] = true;
							qu.push(state(tx, ty, t.msk));
						}
						continue;
					}
					bool f = false;
					for (int j = 0; j < 4; ++j) {
						if (g[tx][ty] != tolower(arr[j].first))
							continue;
						bitset<4> bs = t.msk;
						bs[arr[j].second] = 1;
						if (!vis[tx][ty][bs.to_ulong()]) {
							vis[tx][ty][bs.to_ulong()] = true;
							qu.push(state(tx, ty, bs));
						}
						f = true;
						break;
					}
					if (f)
						continue;
					for (int j = 0; j < 4; ++j) {
						if (g[tx][ty] != arr[j].first)
							continue;
						if (t.msk[arr[j].second] && !vis[tx][ty][t.msk.to_ulong()]) {
							vis[tx][ty][t.msk.to_ulong()] = true;
							qu.push(state(tx, ty, t.msk));
						}
						break;
					}
				}
				if (res != -1)
					break;
			}
			if (res != -1)
				break;
			++lev;
		}
		if (res == -1)
			puts("The poor student is trapped!");
		else
			printf("Escape possible in %d steps.\n", res);
	}
	return 0;
}
