#include <bits/stdc++.h>
using namespace std;

struct state {
	int v, p, l;
	char ch;
	state(int v, int p, int l, char ch) :
			v(v), p(p), l(l), ch(ch) {
	}
};

bool vis[101][32001 * 2];
vector<state> qu;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		int dest;
		scanf("%d", &dest);
		memset(vis, false, sizeof vis);
		qu.clear();
		qu.push_back(state(v[0], -1, 1, '%'));
		vis[0][v[0] + 32000] = true;
		size_t pos = 0;
		int lev = 1;
		while (pos < qu.size() && lev < n) {
			int size = qu.size();
			for (int p = pos, x; p < size; ++p) {
				const state e = qu[p];
				x = e.v + v[lev];
				if (x > -32000 && x < 32000 && !vis[lev][x + 32000]) { // +
					vis[lev][x + 32000] = true;
					qu.push_back(state(x, p, e.l + 1, '+'));
				}
				x = e.v - v[lev];
				if (x > -32000 && x < 32000 && !vis[lev][x + 32000]) { // -
					vis[lev][x + 32000] = true;
					qu.push_back(state(x, p, e.l + 1, '-'));
				}
				x = e.v * v[lev];
				if (x > -32000 && x < 32000 && !vis[lev][x + 32000]) { // *
					vis[lev][x + 32000] = true;
					qu.push_back(state(x, p, e.l + 1, '*'));
				}
				if (v[lev] != 0 && e.v % v[lev] == 0) { // /
					x = e.v / v[lev];
					if (x > -32000 && x < 32000 && !vis[lev][x + 32000]) {
						vis[lev][x + 32000] = true;
						qu.push_back(state(x, p, e.l + 1, '/'));
					}
				}
			}
			++lev;
			pos = size;
		}
		bool can = false;
		vector<char> sol;
		for (int i = qu.size() - 1; i >= 0 && !can; --i) {
			if (qu[i].l != n)
				break;
			if (qu[i].v == dest) {
				for (int at = i; qu[at].ch != '%' && at != -1; at = qu[at].p)
					sol.push_back(qu[at].ch);
				if ((int) sol.size() == n - 1)
					can = true;
			}
		}
		if (!can)
			puts("NO EXPRESSION");
		else {
			int p = 0;
			printf("%d", v[p++]);
			while (!sol.empty() && p < n) {
				printf("%c%d", sol.back(), v[p++]);
				sol.pop_back();
			}
			printf("=%d\n", dest);
		}
	}
	return 0;
}
