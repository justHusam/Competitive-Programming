#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, m, t, l, w;
bool vis[N][N];
queue<pair<int, int> > qu;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

void move(int a, int b, int c, int d, int x, int y) {
	while (a != c || b != d) {
		vis[a][b] = true;
		a += x;
		b += y;
	}
	vis[c][d] = true;
}

int BFS() {
	int res = 0, lev = 0;
	while (!qu.empty() && lev < t) {
		int siz = qu.size();
		while (siz-- != 0) {
			pair<int, int> fr = qu.front();
			qu.pop();
			++res;
			for (int i = 0; i < 4; ++i) {
				int tx = fr.first + dx[i];
				int ty = fr.second + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty])
					continue;
				vis[tx][ty] = true;
				qu.push(make_pair(tx, ty));
			}
		}
		++lev;
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &m) > 0 && m != -1) {
		scanf("%d%d%d%d", &n, &t, &l, &w);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				vis[i][j] = false;
		while (!qu.empty())
			qu.pop();
		while (l-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			swap(a, b);
			vis[a][b] = true;
			qu.push(make_pair(a, b));
		}
		while (w-- != 0) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			--a;
			--b;
			--c;
			--d;
			swap(a, b);
			swap(c, d);
			if (a == c)
				move(a, min(b, d), c, max(b, d), 0, 1);
			else if (b == d)
				move(min(a, c), b, max(a, c), d, 1, 0);
			else if (c > a && d > b)
				move(a, b, c, d, 1, 1);
			else if (a > c && b > d)
				move(a, b, c, d, -1, -1);
			else if (a > c && b < d)
				move(a, b, c, d, -1, 1);
			else if (a < c && b > d)
				move(a, b, c, d, 1, -1);
		}
		printf("%d\n", BFS());
	}
	return 0;
}
