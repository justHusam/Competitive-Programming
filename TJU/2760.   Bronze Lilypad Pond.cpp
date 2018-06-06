#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m, m1, m2, g[N][N];
pair<int, int> src, dest;
queue<pair<int, int> > qu;
bool vis[N][N];

int BFS() {
	qu.push(src);
	vis[src.first][src.second] = true;
	g[dest.first][dest.second] = 1;
	int lev = 1;
	int dx[] = { m1, m1, m2, m2, -m1, -m1, -m2, -m2 };
	int dy[] = { m2, -m2, m1, -m1, m2, -m2, m1, -m1 };
	while (!qu.empty()) {
		int sz = qu.size();
		while (sz--) {
			int x = qu.front().first, y = qu.front().second;
			qu.pop();
			for (int i = 0; i < 8; ++i) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] != 1 || vis[tx][ty])
					continue;
				if (make_pair(tx, ty) == dest)
					return lev;
				qu.push(make_pair(tx, ty));
				vis[tx][ty] = true;
			}
		}
		++lev;
	}
	return -1;
}

int main(int argc, char **argv) {
	scanf("%d%d%d%d", &n, &m, &m1, &m2);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%d", &g[i][j]);
			if (g[i][j] == 3)
				src = make_pair(i, j);
			else if (g[i][j] == 4)
				dest = make_pair(i, j);
		}
	printf("%d\n", BFS());
	return 0;
}
