#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct state {
	int x, y, c;
	state(int x, int y, int c) :
			x(x), y(y), c(c) {
	}
	bool operator<(const state&e) const {
		return c > e.c;
	}
};

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int> > g(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		int r, c, tm;
		scanf("%d%d%d", &r, &c, &tm);
		--r, --c;
		priority_queue<state> qu;
		vector<vector<bool> > vis(n, vector<bool>(m, false));
		qu.push(state(0, 0, g[0][0]));
		int res;
		while (!qu.empty()) {
			const state t = qu.top();
			qu.pop();
			if (vis[t.x][t.y])
				continue;
			vis[t.x][t.y] = true;
			if (t.x == r && t.y == c) {
				res = t.c;
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int tx = t.x + dx[i];
				int ty = t.y + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty])
					continue;
				qu.push(state(tx, ty, t.c + g[tx][ty]));
			}
		}
		if (res > tm)
			puts("NO");
		else
			printf("YES\n%d\n", tm - res);
	}
	return 0;
}
