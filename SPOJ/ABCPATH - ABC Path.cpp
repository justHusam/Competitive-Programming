#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
char grid[55][55];
vector<pair<int, int> > all;
int H, W, cost[55][55];

int BFS(pair<int, int> pos) {
	queue<pair<int, int> > qu;
	int res = 1;
	qu.push(pos);
	cost[pos.first][pos.second] = 1;
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();
		for (int a = 0; a < 8; ++a) {
			int tx = temp.first + dx[a];
			int ty = temp.second + dy[a];
			if (tx >= 0 && ty >= 0 && tx < H && ty < W && grid[temp.first][temp.second] + 1 == grid[tx][ty])
				if (cost[temp.first][temp.second] + 1 > cost[tx][ty]) {
					qu.push(make_pair(tx, ty));
					cost[tx][ty] = cost[temp.first][temp.second] + 1;
					res = max(res, cost[tx][ty]);
				}
		}
	}
	return res;
}

int main(int argc, char **argv) {
	int T = 0;
	while (scanf("%i %i", &H, &W) && make_pair(H, W) != make_pair(0, 0)) {
		memset(cost, 0, sizeof cost);
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) {
				scanf(" %c", &grid[i][j]);
				if (grid[i][j] == 'A')
					all.push_back(make_pair(i, j));
			}
		int res = 0;
		for (size_t i = 0; i < all.size(); ++i)
			res = max(res, BFS(all[i]));
		printf("Case %i: %i\n", ++T, res);
		all.clear();
	}
	return 0;
}
