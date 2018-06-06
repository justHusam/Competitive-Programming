#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int main() {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int> > g(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		priority_queue<pair<int, pair<int, int> > > qu;
		vector<vector<bool> > vis(n, vector<bool>(m));
		vector<vector<int> > cost(n, vector<int>(m, oo));
		qu.push(make_pair(-g[0][0], make_pair(0, 0)));
		int res;
		while (!qu.empty()) {
			pair<int, pair<int, int> > e = qu.top();
			qu.pop();
			if (vis[e.second.first][e.second.second])
				continue;
			vis[e.second.first][e.second.second] = true;
			if (e.second == make_pair(n - 1, m - 1)) {
				res = -e.first;
				break;
			}
			for (int a = 0; a < 4; ++a) {
				int tx = e.second.first + dx[a];
				int ty = e.second.second + dy[a];
				if (tx >= 0 && ty >= 0 && tx < n && ty < m && !vis[tx][ty]) {
					int c = -e.first + g[tx][ty];
					if (c < cost[tx][ty]) {
						cost[tx][ty] = c;
						qu.push(make_pair(-c, make_pair(tx, ty)));
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
