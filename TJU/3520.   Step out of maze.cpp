#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int x, y, p;
	char a;
	state(int x, int y, int p, int a) :
			x(x), y(y), p(p), a(a) {
	}
};

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, g[101][101];
		bool vis[101][101] = { };
		scanf("%d%d", &n, &m);
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < m; ++b)
				scanf("%d", &g[a][b]);
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		vector<state> qu;
		qu.push_back(state(x, y, -1, '?'));
		vis[x][y] = true;
		size_t pos = 0;
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		char da[] = { 'U', 'D', 'L', 'R' };
		bool done = false;
		while (pos < qu.size()) {
			int siz = qu.size();
			for (int p = pos; p < siz; ++p) {
				const state t = qu[p];
				for (int a = 0; a < 4; ++a) {
					int tx = t.x + dx[a];
					int ty = t.y + dy[a];
					// final
					if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
						qu.push_back(state(tx, ty, p, da[a]));
						done = true;
						break;
					}
					if (vis[tx][ty] || g[tx][ty])
						continue;
					vis[tx][ty] = true;
					qu.push_back(state(tx, ty, p, da[a]));
				}
			}
			if (done)
				break;
			pos = siz;
		}
		vector<char> v;
		for (int u = qu.size() - 1; qu[u].a != '?'; u = qu[u].p)
			v.push_back(qu[u].a);
		putchar(v.back());
		v.pop_back();
		for (; v.size(); v.pop_back()) {
			putchar(' ');
			putchar(v.back());
		}
		putchar('\n');
	}
	return 0;
}
