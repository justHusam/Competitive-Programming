#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int i, j, c;
	state(int i, int j, int c) :
			i(i), j(j), c(c) {
	}
	inline bool operator<(const state&e) const {
		if (e.c != c)
			return e.c < c;
		if (e.i != i)
			return e.i < i;
		return e.j < j;
	}
};

int n, m;
char g[222][222];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

inline bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && g[x][y] != 'T';
}

int calc(int x, int y) {
	int res = 0;
	if (g[x][y] != '.')
		++res;
	for (int i = 0; i < 2; ++i)
		for (int j = 1;; ++j) {
			int tx = x + dx[i] * j;
			int ty = y + dy[i] * j;
			if (!check(tx, ty))
				break;
			if (g[tx][ty] == 'H')
				++res;
		}
	for (int i = 2; i < 4; ++i)
		for (int j = 1;; ++j) {
			int tx = x + dx[i] * j;
			int ty = y + dy[i] * j;
			if (!check(tx, ty))
				break;
			if (g[tx][ty] == 'V')
				++res;
		}
	return res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf(" %c", &g[i][j]);
		state v = state(-1, -1, -1);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (g[i][j] != 'T') {
					state temp = state(i, j, calc(i, j));
					if (temp < v)
						v = temp;
				}
		printf("Case %d: %d %d %d\n", k++, v.c, v.i, v.j);
	}
	return 0;
}
