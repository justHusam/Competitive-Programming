#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 0, 1, -1, 0, 1 };
int dy[] = { -1, -1, 0, 0, 1, 1 };

int n;
bool vis[202][202];
char g[202][202];
queue<pair<int, int> > Q[2];

bool BFS(pair<int, int> pt, char ch) {
	queue<pair<int, int> > qu;
	memset(vis, false, sizeof vis);
	qu.push(pt);
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();
		for (int i = 0; i < 6; ++i) {
			int tx = temp.first + dx[i];
			int ty = temp.second + dy[i];
			if (tx >= 0 && ty >= 0 && tx < n && ty < n && !vis[tx][ty] && g[tx][ty] == ch) {
				if ((ch == 'w' && ty == n - 1) || (ch == 'b' && tx == n - 1))
					return true;
				vis[tx][ty] = true;
				qu.push( { tx, ty });
			}
		}
	}
	return false;
}

char calc() {
	// 0 = black --- 1 = white
	size_t siz[] = { Q[0].size(), Q[1].size() };
	bool F = false;
	char ch[] = { 'b', 'w' };
	if (siz[0] == 0)
		return 'W';
	if (siz[1] == 0)
		return 'B';
	int in = siz[0] < siz[1] ? 0 : 1;
	while (siz[in]-- != 0 && !F) {
		F = BFS(Q[in].front(), ch[in]);
		Q[in].pop();
	}
	if (F)
		return toupper(ch[in]);
	return toupper(ch[!in]);
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < 2; ++i)
			while (!Q[i].empty())
				Q[i].pop();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf(" %c", &g[i][j]);
				if (i == 0 && g[i][j] == 'b')
					Q[0].push( { i, j });
				if (j == 0 && g[i][j] == 'w')
					Q[1].push( { i, j });
			}
		}
		printf("%d %c\n", cas++, calc());
	}
	return 0;
}
