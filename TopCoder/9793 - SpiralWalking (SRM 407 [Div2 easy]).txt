#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

class SpiralWalking {
public:
	bool vis[50][50];
	vector<string> g;
	int n, m;

	int totalPoints(vector<string> levelMap) {
		g = levelMap;
		n = levelMap.size();
		m = levelMap[0].size();
		return DFS(0, 0, 0, n * m - 1);
	}

	int DFS(int x, int y, int d, int w) {
		int tx = x + dx[d];
		int ty = y + dy[d];
		vis[x][y] = true;
		if (w == 0)
			return g[x][y] - '0';
		if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty])
			return DFS(x + dx[(d + 1) % 4], y + dy[(d + 1) % 4], (d + 1) % 4, w - 1);
		return DFS(tx, ty, d, w - 1) + (g[x][y] - '0');
	}
};
