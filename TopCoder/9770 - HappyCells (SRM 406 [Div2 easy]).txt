#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class HappyCells {
public:
	vector<int> getHappy(vector<string> grid) {
		int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
		int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
		int n = grid.size(), m = grid[0].size();
		vector<int> res(3, 0);
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y) {
				if (grid[x][y] == 'X')
					continue;
				int a = 0, aa = 0, b = 0, bb = 0;
				for (int i = 0; i < 4; ++i) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx < 0 || ty < 0 || tx >= n || ty >= m)
						continue;
					++a;
					if (grid[tx][ty] == 'X')
						++aa;
				}
				for (int i = 4; i < 8; ++i) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx < 0 || ty < 0 || tx >= n || ty >= m)
						continue;
					++b;
					if (grid[tx][ty] == 'X')
						++bb;
				}
				if (a == aa && b == bb)
					++res[0];
				else if (a == aa && b != bb)
					++res[1];
				else if (a != aa && b == bb)
					++res[2];
			}
		return res;
	}
};
