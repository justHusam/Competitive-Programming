#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 8, oo = 1000000000;
char g[N][N + 1];
int n, dp[8][1 << 8], cost[N][N][N][N], m;
queue<pair<int, int> > qu;
int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 }, dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
pair<int, int> pos[8];

void BFS(int x, int y, int cost[N][N]) {
	while (!qu.empty())
		qu.pop();
	cost[x][y] = 0;
	qu.push(make_pair(x, y));
	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		for (int i = 0; i < N; ++i) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N || cost[tx][ty] != -1 || g[tx][ty] == 'K' || g[tx][ty] == 'p')
				continue;
			cost[tx][ty] = cost[x][y] + 1;
			qu.push(make_pair(tx, ty));
		}
	}
}

inline int calc(const pair<int, int> &a, const pair<int, int> &b) {
	return cost[a.first][a.second][b.first][b.second];
}

int calc(int at, int mask) {
	if (mask == (1 << m) - 1)
		return 0;
	int &res = dp[at][mask];
	if (res != -1)
		return res;
	res = oo;
	for (int i = 0; i < m; ++i)
		if (((mask >> i) & 1) == 0) {
			int need = calc(pos[at], pos[i]);
			if (need != -1)
				res = min(res, calc(i, mask | (1 << i)) + need);
		}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf(" %d", &n);
		for (int i = 0; i < N; ++i)
			scanf("%s", g[i]);
		m = 0;
		memset(cost, -1, sizeof cost);
		int x, y;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (g[i][j] == 'k') {
					x = i, y = j;
					BFS(i, j, cost[i][j]);
				} else if (g[i][j] == 'P') {
					pos[m++] = make_pair(i, j);
					BFS(i, j, cost[i][j]);
				}
		memset(dp, -1, sizeof dp);
		int res = oo;
		for (int i = 0; i < m; ++i) {
			int need = calc(make_pair(x, y), pos[i]);
			if (need != -1)
				res = min(res, calc(i, 1 << i) + need);
		}
		if (m == 0 || res <= n)
			puts("Yes");
		else
			puts("No");

	}
	return 0;
}
