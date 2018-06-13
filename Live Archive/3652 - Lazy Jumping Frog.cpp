#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dx[] = { -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
int dy[] = { -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2 };
int dc[] = { 7, 6, 5, 6, 7, 6, 3, 2, 3, 6, 5, 2, 2, 5, 6, 3, 2, 3, 6, 7, 6, 5, 6, 7 };
vector<vector<bool> > vis;
vector<vector<int> > cost;

int main(int argc, char **argv) {
	int R, C, w, r1, r2, c1, c2, sr, sc, tr, tc;
	while (scanf("%d%d", &C, &R) && R != 0) {
		vis.clear();
		vis.resize(R, vector<bool>(C, 0));
		scanf("%d%d%d%d%d", &sc, &sr, &tc, &tr, &w);
		--sc, --sr, --tc, --tr;
		while (w-- != 0) {
			scanf("%d%d%d%d", &c1, &r1, &c2, &r2);
			--c1, --r1, --c2, --r2;
			for (int i = r1; i <= r2; ++i)
				for (int j = c1; j <= c2; ++j)
					vis[i][j] = false;
		}
		priority_queue<pair<int, pair<int, int> > > qu;
		cost.clear();
		cost.resize(R, vector<int>(C, 2e9));
		qu.push(make_pair(0, make_pair(sr, sc)));
		cost[sr][sc] = 0;
		int res = -1;
		while (!qu.empty()) {
			pair<int, pair<int, int> > e = qu.top();
			qu.pop();
			if (e.second.first == tr && e.second.second == tc) {
				res = -e.first;
				break;
			}
			if (vis[e.second.first][e.second.second])
				continue;
			vis[e.second.first][e.second.second] = true;
			for (int i = 0; i < 24; ++i) {
				int tx = e.second.first + dx[i];
				int ty = e.second.second + dy[i];
				int tc = -e.first + dc[i];
				if (tx < 0 || ty < 0 || tx >= R || ty >= C || vis[tx][ty] || tc >= cost[tx][ty])
					continue;
				cost[tx][ty] = tc;
				qu.push(make_pair(-tc, make_pair(tx, ty)));
			}
		}
		if (res == -1)
			puts("impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
