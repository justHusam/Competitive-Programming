#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<char> > g;
vector<pair<int, int> > open;
vector<vector<bool> > vis;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

int main(int argc, char **argv) {
	int t;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		g.clear();
		g.resize(n, vector<char>(m));
		open.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == '.' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
					open.push_back(make_pair(i, j));
			}
		if (open.size() != 2) {
			puts("invalid");
			continue;
		}
		vis.clear();
		vis.resize(n, vector<bool>(m, false));
		queue<pair<int, int> > qu;
		qu.push(open[0]);
		vis[open[0].first][open[0].second] = true;
		bool can = false;
		while (!qu.empty()) {
			int x = qu.front().first, y = qu.front().second;
			qu.pop();
			for (int i = 0; i < 4; ++i) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || g[tx][ty] == '#')
					continue;
				vis[tx][ty] = true;
				qu.push(make_pair(tx, ty));
				if (make_pair(tx, ty) == open[1]) {
					can = true;
					break;
				}
			}
			if (can)
				break;
		}
		if (can)
			puts("valid");
		else
			puts("invalid");
	}
	return 0;
}
