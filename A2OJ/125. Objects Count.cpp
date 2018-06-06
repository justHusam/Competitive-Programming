#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int> > g(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		int v;
		scanf("%d", &v);
		vector<int> vv(v);
		for (int i = 0; i < v; ++i)
			scanf("%d", &vv[i]);
		int dd;
		scanf("%d", &dd);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				pair<int, int> res(oo, oo);
				for (int k = 0; k < v; ++k) {
					int diff = abs(g[i][j] - vv[k]);
					if (diff < res.first || (diff == res.first && vv[k] < res.second))
						res = make_pair(diff, vv[k]);
				}
				g[i][j] = res.second;
			}
		vector<vector<bool> > vis(n, vector<bool>(m, false));
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (vis[i][j])
					continue;
				int temp = 1, val = g[i][j];
				queue<pair<int, int> > qu;
				vis[i][j] = true;
				qu.push(make_pair(i, j));
				while (!qu.empty()) {
					pair<int, int> e = qu.front();
					qu.pop();
					for (int k = 0; k < 4; ++k) {
						int tx = e.first + dx[k];
						int ty = e.second + dy[k];
						if (tx >= 0 && ty >= 0 && tx < n && ty < m && !vis[tx][ty] && g[tx][ty] == val) {
							vis[tx][ty] = true;
							++temp;
							qu.push(make_pair(tx, ty));
						}
					}
				}
				if (temp >= dd)
					++res;
			}
		printf("%d\n", res);
	}
	return 0;
}
