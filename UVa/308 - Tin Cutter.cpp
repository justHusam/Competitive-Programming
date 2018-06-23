#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 400;
int p, n, m, G[N][N], id;
char g[N][N];
vector<int> v, hsX, hsY;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
bool vis[N][N];
queue<pair<int, int> > qu;
vector<pair<int, int> > all;

inline void build(vector<int> &hs) {
	sort(hs.begin(), hs.end());
	hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
}

inline int get(int v, const vector<int> &hs) {
	int k = lower_bound(hs.begin(), hs.end(), v) - hs.begin();
	return k << 1;
}

void BFS(int x, int y) {
	all.clear();
	vis[x][y] = true;
	qu.push(make_pair(x, y));
	all.push_back(make_pair(x, y));
	bool ok = true;
	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
				ok = false;
				continue;
			}
			if (vis[tx][ty])
				continue;
			all.push_back(make_pair(tx, ty));
			if (g[tx][ty] == '.') {
				vis[tx][ty] = true;
				qu.push(make_pair(tx, ty));
			}
		}
	}
	if (ok) {
		for (int i = 0; i < (int) all.size(); ++i)
			G[all[i].first][all[i].second] = id;
		++id;
	}
}

void go(int x, int y) {
	G[x][y] = -1;
	qu.push(make_pair(x, y));
	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || G[tx][ty] == -1)
				continue;
			G[tx][ty] = -1;
			qu.push(make_pair(tx, ty));
		}
	}
}

int main(int argc, char **argv) {
	while (scanf("%d", &p) && p != 0) {
		v.clear();
		hsX.clear();
		hsY.clear();
		for (int i = 0; i < p; ++i) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			v.push_back(a);
			v.push_back(b);
			v.push_back(c);
			v.push_back(d);
			hsX.push_back(a);
			hsX.push_back(c);
			hsY.push_back(b);
			hsY.push_back(d);
		}
		build(hsX);
		build(hsY);
		n = (hsX.size() << 1);
		m = (hsY.size() << 1);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				g[i][j] = '.';
				G[i][j] = -1;
				vis[i][j] = false;
			}
		for (int i = 0; i < (int) v.size(); i += 4) {
			int a = get(v[i], hsX);
			int b = get(v[i + 1], hsY);
			int c = get(v[i + 2], hsX);
			int d = get(v[i + 3], hsY);
			if (a == c) {
				if (d < b)
					swap(b, d);
				while (b <= d)
					g[a][b++] = '*';
			} else if (b == d) {
				if (c < a)
					swap(a, c);
				while (a <= c)
					g[a++][b] = '*';
			}
		}
		id = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (!vis[i][j] && g[i][j] == '.')
					BFS(i, j);
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (G[i][j] != -1) {
					++res;
					go(i, j);
				}
		printf("%d\n", res);
	}
	return 0;
}
