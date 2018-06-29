#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char g[100][100];
bool vis[100][100];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m, idx[100][100], id, caseN;

inline void DFS(int x, int y) {
	idx[x][y] = id;
	vis[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int tx = dx[i] + x;
		int ty = dy[i] + y;
		if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || g[tx][ty] == '.')
			continue;
		DFS(tx, ty);
	}
}

inline void _DFS(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int tx = dx[i] + x;
		int ty = dy[i] + y;
		if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || g[tx][ty] != 'X')
			continue;
		_DFS(tx, ty);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &m, &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf(" %c", &g[i][j]);
		id = 0;
		memset(vis, false, sizeof vis);
		memset(idx, 0, sizeof idx);
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < m; ++b)
				if (idx[a][b] == 0 && g[a][b] == '*') {
					++id;
					DFS(a, b);
				}
		map<int, int> hs;
		memset(vis, false, sizeof vis);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (!vis[i][j] && g[i][j] == 'X') {
					++hs[idx[i][j]];
					_DFS(i, j);
				}
		vector<int> res;
		map<int, int>::iterator it;
		for (it = hs.begin(); it != hs.end(); ++it)
			res.push_back(it->second);
		sort(res.begin(), res.end());
		printf("Throw %d\n", ++caseN);
		for (size_t i = 0; i < res.size(); ++i)
			printf("%s%d", i ? " " : "", res[i]);
		puts("\n");
	}
	return 0;
}
