#include <bits/stdc++.h>
using namespace std;

int dl[] = { 1, -1, 0, 0, 0, 0 }, dx[] = { 0, 0, 0, 0, 1, -1 }, dy[] = { 0, 0, 1, -1, 0, 0 };

int L, R, C;
char g[35][35][35];

bool check(int l, int x, int y) {
	return l >= 0 && x >= 0 && y >= 0 && l < L && x < R && y < C && g[l][x][y] != '#';
}

int BFS(pair<int, pair<int, int> > src) {
	queue<pair<int, pair<int, int> > > qu;
	int lev = 0;
	qu.push(src);
	g[src.first][src.second.first][src.second.second] = '#'; // visited
	while (!qu.empty()) {
		int siz = qu.size();
		while (siz-- != 0) {
			pair<int, pair<int, int> > e = qu.front();
			qu.pop();
			for (int i = 0; i < 6; ++i) {
				int tl = e.first + dl[i];
				int tx = e.second.first + dx[i];
				int ty = e.second.second + dy[i];
				if (check(tl, tx, ty)) {
					if (g[tl][tx][ty] == 'E')
						return lev + 1;
					g[tl][tx][ty] = '#';
					qu.push(make_pair(tl, make_pair(tx, ty)));
				}
			}
		}
		++lev;
	}
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &L, &R, &C) > 0 && L != 0) {
		pair<int, pair<int, int> > src;
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < R; ++j)
				for (int k = 0; k < C; ++k) {
					scanf(" %c", &g[i][j][k]);
					if (g[i][j][k] == 'S')
						src = make_pair(i, make_pair(j, k));
				}
		int res = BFS(src);
		if (res != -1)
			printf("Escaped in %i minute(s).\n", res);
		else
			puts("Trapped!");
	}
	return 0;
}
