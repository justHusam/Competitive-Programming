#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

/*
 * You got a dream, you gotta protect it.
 */

struct state {
	int f, x, y;
	state(int f, int x, int y) :
			f(f), x(x), y(y) {
	}
};

int main(int argc, char **argv) {
	int n, m, f, cas = 1;
	while (scanf("%d%d%d", &n, &m, &f) > 0 && n != 0) {
		char g[21][21][21];
		for (int i = 0; i < f; ++i)
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < m; ++k)
					scanf(" %c", &g[i][j][k]);
		bool vis[21][21][21] = { };
		queue<state> qu;
		qu.push(state(0, 0, 0));
		vis[0][0][0] = 1;
		int lev = 1, res = -1;
		while (!qu.empty()) {
			int siz = qu.size();
			while (siz-- != 0) {
				const state t = qu.front();
				qu.pop();
				if (!vis[(t.f + 1) % f][t.x][t.y] && g[(t.f + 1) % f][t.x][t.y] != '1') {
					vis[(t.f + 1) % f][t.x][t.y] = true;
					qu.push(state((t.f + 1) % f, t.x, t.y));
				}
				for (int i = 0; i < 4; ++i) {
					int tx = t.x + dx[i];
					int ty = t.y + dy[i];
					int tf = (t.f + 1) % f;
					if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tf][tx][ty] || g[tf][tx][ty] == '1')
						continue;
					if (make_pair(tx, ty) == make_pair(n - 1, m - 1)) {
						res = lev;
						break;
					}
					vis[tf][tx][ty] = true;
					qu.push(state(tf, tx, ty));
				}
				if (res != -1)
					break;
			}
			if (res != -1)
				break;
			++lev;
		}
		printf("Case %d: ", cas++);
		if (res == -1)
			puts("Luke and Leia cannot escape.");
		else
			printf("Luke and Leia can escape in %d steps.\n", res);
	}
	return 0;
}
