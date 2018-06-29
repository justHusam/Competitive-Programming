#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 11, oo = 2e9, M = 20437;
int n, alpha, best, cost[N][N], dp[N][N], vis[N][N], vs;
char g[N][N];
pair<int, int> v[26];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

int BFS(pair<int, int>&src, pair<int, int>&tar) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cost[i][j] = oo;
	queue<pair<int, int> > qu;
	qu.push(src);
	cost[src.first][src.second] = 0;
	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n || cost[x][y] + 1 >= cost[tx][ty] || g[tx][ty] != '.')
				continue;
			cost[tx][ty] = cost[x][y] + 1;
			qu.push(make_pair(tx, ty));
		}
	}
	return cost[tar.first][tar.second];
}

int calc(int x, int y, int w, int xx, int yy) {
	if (x == xx && y == yy)
		return 1;
	int &res = dp[x][y];
	if (vis[x][y] == vs)
		return res;
	vis[x][y] = vs;
	res = 0;
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= n || g[tx][ty] != '.')
			continue;
		if (w + 1 + cost[tx][ty] == best)
			res = (res + calc(tx, ty, w + 1, xx, yy)) % M;
	}
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		alpha = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf(" %c", &g[i][j]);
				if (isalpha(g[i][j])) {
					++alpha;
					v[g[i][j] - 'A'] = make_pair(i, j);
				}
			}
		int res = 0, ways = 1;
		for (int i = 1; i < alpha; ++i) {
			g[v[i].first][v[i].second] = g[v[i - 1].first][v[i - 1].second] = '.';
			best = BFS(v[i], v[i - 1]);
			if (best == oo) {
				res = -1;
				break;
			}
			++vs;
			res += best;
			ways = (ways * calc(v[i - 1].first, v[i - 1].second, 0, v[i].first, v[i].second)) % M;
		}
		printf("Case %d: ", cas++);
		if (res == -1)
			puts("Impossible");
		else
			printf("%d %d\n", res, ways);
	}
	return 0;
}
