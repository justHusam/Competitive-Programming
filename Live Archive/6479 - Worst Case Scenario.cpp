#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
char g[N][N];
int n, m, vis[N][N], vs;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

void move(int x, int y) {
	queue<pair<int, int> > qu;
	vis[x][y] = ++vs;
	qu.push(make_pair(x, y));
	while (!qu.empty()) {
		pair<int, int> fr = qu.front();
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = fr.first + dx[i];
			int ty = fr.second + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] == vs || g[tx][ty] == 'X')
				continue;
			if (g[tx][ty] == 'A')
				g[tx][ty] = 'B';
			else if (g[tx][ty] == 'B')
				g[tx][ty] = 'C';
			else if (g[tx][ty] == 'C')
				g[tx][ty] = 'D';
			else if (g[tx][ty] == 'D') {
				vis[tx][ty] = vs;
				qu.push(make_pair(tx, ty));
			}
		}
	}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &m, &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		int q;
		scanf("%d", &q);
		while (q-- != 0) {
			int x, y;
			scanf("%d%d", &y, &x);
			if (g[x][y] == 'A')
				g[x][y] = 'B';
			else if (g[x][y] == 'B')
				g[x][y] = 'C';
			else if (g[x][y] == 'C')
				g[x][y] = 'D';
			else if (g[x][y] == 'D')
				move(x, y);
		}
		for (int i = 0; i < n; ++i)
			puts(g[i]);
	}
	return 0;
}
