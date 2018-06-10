#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20;
int n, w, b;
char g[N][N];
bool vis[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
vector<vector<pair<int, int> > > comp;

void DFS(int x, int y) {
	vis[x][y] = true;
	comp.back().push_back(make_pair(x, y));
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < n && ty < n && !vis[tx][ty] && g[tx][ty] == '.')
			DFS(tx, ty);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		scanf("%d%d", &b, &w);
		for (int i = 0; i < n; ++i)
			fill(g[i], g[i] + n, '.');
		int x, y;
		while (b-- != 0) {
			scanf("%d%d", &x, &y);
			g[--x][--y] = 'b';
		}
		while (w-- != 0) {
			scanf("%d%d", &x, &y);
			g[--x][--y] = 'w';
		}
		comp.clear();
		memset(vis, false, sizeof vis);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (!vis[i][j] && g[i][j] == '.') {
					comp.push_back(vector<pair<int, int> >());
					DFS(i, j);
				}
		w = b = 0;
		for (int i = 0; i < comp.size(); ++i) {
			bool go[2] = { };
			for (int j = 0; j < comp[i].size(); ++j)
				for (int k = 0; k < 4; ++k) {
					int tx = comp[i][j].first + dx[k];
					int ty = comp[i][j].second + dy[k];
					if (tx < 0 || ty < 0 || tx >= n || ty >= n || g[tx][ty] == '.')
						continue;
					if (g[tx][ty] == 'b')
						go[0] = true;
					else
						go[1] = true;
				}
			if (go[0] && go[1])
				continue;
			if (go[0])
				b += comp[i].size();
			else if (go[1])
				w += comp[i].size();
		}
		if (w == b)
			puts("Draw");
		else if (w > b)
			printf("White wins by %d\n", w - b);
		else
			printf("Black wins by %d\n", b - w);
	}
	return 0;
}
