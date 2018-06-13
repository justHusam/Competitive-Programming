#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int x, y, msk;
	state(int x, int y, int msk) :
			x(x), y(y), msk(msk) {
	}
};

const int N = 8;
int p, g[N][N];
int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 }, dy[] = { -2, 2, -1, 1, -2, 2, -1, 1 };
queue<state> qu;
bool vis[N][N][N][1 << N];

int BFS(int x, int y) {
	while (!qu.empty())
		qu.pop();
	memset(vis, false, sizeof vis);
	vis[x][y][0][0] = true;
	qu.push(state(x, y, 0));
	int lev = 0;
	while (!qu.empty()) {
		int sz = qu.size();
		while (sz--) {
			state e = qu.front();
			qu.pop();
			for (int i = 0; i < N; ++i) {
				int tx = e.x + dx[i];
				int ty = e.y + dy[i];
				int nmsk = e.msk;
				if (tx < 0 || ty < 0 || tx >= N || ty >= N)
					continue;
				if (tx - lev >= 0 && g[tx - lev][ty] != -1)
					nmsk |= 1 << g[tx - lev][ty];
				if (vis[tx][ty][lev][nmsk])
					continue;
				if (nmsk == (1 << p) - 1)
					return lev + 1;
				vis[tx][ty][lev][nmsk] = true;
				qu.push(state(tx, ty, nmsk));
			}
		}
		++lev;
		if (lev == 8)
			break;
	}
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d", &p) && p != 0) {
		memset(g, -1, sizeof g);
		for (int i = 0, v; i < p; ++i) {
			scanf("%d", &v);
			--v;
			g[v / N][v % N] = i;
		}
		int src;
		scanf("%d", &src);
		--src;
		int res = BFS(src / N, src % N);
		if (res == -1)
			puts("impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
