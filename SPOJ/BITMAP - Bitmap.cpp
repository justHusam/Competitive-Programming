#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

string s;
char grid[190][190];
queue<pair<int, int> > qu;
int T, n, m, cost[190][190];

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '0';
}

void BFS() {
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();
		for (int a = 0; a < 4; a++) {
			int tx = temp.first + dx[a];
			int ty = temp.second + dy[a];
			if (check(tx, ty) && cost[temp.first][temp.second] + 1 < cost[tx][ty]) {
				qu.push(make_pair(tx, ty));
				cost[tx][ty] = cost[temp.first][temp.second] + 1;
			}
		}
	}
}

int main(int argc, char **argv) {
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &grid[i][j]);
				cost[i][j] = 1e9;
				if (grid[i][j] == '1') {
					cost[i][j] = 0;
					qu.push(make_pair(i, j));
				}
			}
		}
		BFS();
		for (int i = 0; i < n; i++) {
			printf("%d", cost[i][0]);
			for (int b = 1; b < m; b++)
				printf(" %d", cost[i][b]);
			printf("\n");
		}
	}
	return 0;
}
