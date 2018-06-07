#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int x, y, c;
	state(int x, int y, int c) :
			x(x), y(y), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

const int N = 51;
int n, m, cost[N][N], best;
char g[N][N];
vector<pair<int, int> > pos;
bool vis[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
vector<int> v;

void Dijkstra(int x, int y) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cost[i][j] = 2e9, vis[i][j] = false;
	cost[x][y] = 0;
	priority_queue<state> qu;
	qu.push(state(x, y, 0));
	while (!qu.empty()) {
		state e = qu.top();
		qu.pop();
		if (vis[e.x][e.y])
			continue;
		vis[e.x][e.y] = true;
		for (int i = 0; i < 4; ++i) {
			int tx = e.x + dx[i];
			int ty = e.y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty])
				continue;
			if (!isdigit(g[tx][ty]) || !isdigit(g[e.x][e.y])) {
				if (e.c + 2 >= cost[tx][ty])
					continue;
				cost[tx][ty] = e.c + 2;
				qu.push(state(tx, ty, cost[tx][ty]));
			} else {
				int diff = abs(g[e.x][e.y] - g[tx][ty]);
				if (diff > 1 || (diff == 0 && e.c + 1 >= cost[tx][ty]) || (diff == 1 && e.c + 3 >= cost[tx][ty]))
					continue;
				cost[tx][ty] = e.c + (diff == 0 ? 1 : 3);
				qu.push(state(tx, ty, cost[tx][ty]));
			}
		}
	}
}

void go(int i, int a, int b, int lstA, int lstB) {
	if (max(a, b) >= best)
		return;
	if (i == (int) v.size()) {
		best = max(a, b);
		return;
	}
	if (lstA == -1) {
		go(i + 1, a + v[i] * 2, b, -1, lstB);
		go(i + 1, a + v[i], b, i, lstB);
	}
	if (lstB == -1) {
		go(i + 1, a, b + v[i] * 2, lstA, -1);
		go(i + 1, a, b + v[i], lstA, i);
	}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		pos.clear();
		int x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == '$')
					pos.push_back(make_pair(i, j));
				else if (g[i][j] == 'X')
					x = i, y = j;
			}
		Dijkstra(x, y);
		v.clear();
		bool can = true;
		for (size_t i = 0; i < pos.size() && can; ++i) {
			v.push_back(cost[pos[i].first][pos[i].second]);
			can &= v.back() != 2e9;
		}
		if (!can) {
			puts("-1");
			continue;
		}
		sort(v.begin(), v.end());
		best = 2e9;
		go(0, 0, 0, -1, -1);
		printf("%d\n", best);
	}
	return 0;
}
