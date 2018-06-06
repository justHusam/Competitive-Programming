#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m, x, y;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		--x, --y;
		bool vis[202][202] = { };
		queue<pair<int, int> > qu;
		int res = 1;
		qu.push(make_pair(x, y));
		vis[x][y] = 1;
		while (!qu.empty()) {
			pair<int, int> temp = qu.front();
			qu.pop();
			for (int i = 0; i < 8; ++i) {
				int tx = temp.first + dx[i];
				int ty = temp.second + dy[i];
				if (tx >= 0 && ty >= 0 && tx < n && ty < m && !vis[tx][ty]) {
					++res;
					vis[tx][ty] = true;
					qu.push(make_pair(tx, ty));
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
