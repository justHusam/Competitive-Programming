#include <bits/stdc++.h>
using namespace std;

char g[15][15];
vector<pair<int, int> > v;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
int vis[15][15], vs, sz[15], col;

void DFS(int x, int y, char col) {
	vis[x][y] = vs;
	v.push_back(make_pair(x, y));
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < 12 && ty < 10 && g[tx][ty] == col && vis[tx][ty] != vs)
			DFS(tx, ty, col);
	}
}

inline void modify(int x, int y) {
	for (int i = x; i < sz[y]; ++i)
		g[i][y] = g[i + 1][y];
	--sz[y];
}

inline void modify(int y) {
	for (int i = 0; i < 12; ++i)
		for (int j = y; j < col; ++j)
			g[i][j] = g[i][j + 1];
	for (int i = y; i < col; ++i)
		sz[i] = sz[i + 1];
	--col;
}

int calc(int x, int y) {
	v.clear();
	if (g[x][y] == 'x')
		return 0;
	++vs;
	DFS(x, y, g[x][y]);
	if (v.size() < 3)
		return 0;
	for (size_t i = 0; i < v.size(); ++i)
		g[v[i].first][v[i].second] = 'x';
	for (int j = 0; j < col; ++j)
		for (int i = sz[j] - 1; i >= 0; --i)
			if (g[i][j] == 'x')
				modify(i, j);
	for (int i = col - 1; i >= 0; --i)
		if (sz[i] == 0)
			modify(i);
	return v.size();
}

int main(int argc, char **argv) {
	int q;
	while (scanf("%d", &q) && q != 0) {
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j)
				g[i][j] = 'x';
			sz[i] = 12;
		}
		col = 10;
		for (int i = 11; i >= 0; --i)
			scanf("%s", g[i]);
		for (int i = 0; i < 12; ++i)
			g[i][10] = 'x';
		char a;
		int b, res = 120;
		while (q-- != 0) {
			scanf(" %c%d", &a, &b);
			res -= calc(b - 1, a - 'a');
		}
		printf("%d\n", res);
	}
	return 0;
}
