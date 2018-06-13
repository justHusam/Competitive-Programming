#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int x, y;
	ll c;
	state(int x, int y, ll c) :
			x(x), y(y), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

const int N = 1e3;
int k, n, m, ch[26], g[N][N];
ll cost[N][N];
bool vis[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

ll Dijkstra(int x, int y) {
	priority_queue<state> qu;
	qu.push(state(x, y, 0));
	cost[x][y] = 0;
	while (!qu.empty()) {
		state e = qu.top();
		qu.pop();
		if (e.x == 0 || e.x == n - 1 || e.y == 0 || e.y == m - 1)
			return e.c;
		if (vis[e.x][e.y])
			continue;
		vis[e.x][e.y] = true;
		for (int i = 0; i < 4; ++i) {
			int tx = e.x + dx[i];
			int ty = e.y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || e.c + g[tx][ty] >= cost[tx][ty])
				continue;
			cost[tx][ty] = e.c + g[tx][ty];
			qu.push(state(tx, ty, e.c + g[tx][ty]));
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &k, &m, &n);
		while (k--) {
			char a;
			int b;
			scanf(" %c%d", &a, &b);
			ch[a - 'A'] = b;
		}
		int x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				char c;
				scanf(" %c", &c);
				if (c == 'E') {
					x = i;
					y = j;
				} else
					g[i][j] = ch[c - 'A'];
				vis[i][j] = false;
				cost[i][j] = 2e15;
			}
		printf("%lld\n", Dijkstra(x, y));
	}
	return 0;
}
