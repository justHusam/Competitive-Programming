#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001;
int n, m, cost[N][N];
char g[N][N];
deque<pair<int, int> > qu;
bool vis[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				cost[i][j] = 1e9;
				vis[i][j] = false;
			}
		while (!qu.empty())
			qu.pop_back();
		qu.push_back(make_pair(0, 0));
		cost[0][0] = 0;
		while (!qu.empty()) {
			int x = qu.front().first, y = qu.front().second;
			qu.pop_front();
			if (x == n - 1 && y == m - 1)
				break;
			if (vis[x][y])
				continue;
			vis[x][y] = true;
			for (int i = 0; i < 4; ++i) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || cost[x][y] + (g[tx][ty] != g[x][y]) >= cost[tx][ty])
					continue;
				cost[tx][ty] = cost[x][y] + (g[tx][ty] != g[x][y]);
				if (g[tx][ty] == g[x][y])
					qu.push_front(make_pair(tx, ty));
				else
					qu.push_back(make_pair(tx, ty));
			}
		}
		printf("%d\n", cost[n - 1][m - 1]);
	}
	return 0;
}
