#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m, L;
char g[55][55], s[300];

bool check(int x, int y) {
	for (int i = 0; i < 8; ++i) {
		bool can = true;
		for (int j = 1; j < L && can; ++j) {
			int tx = x + dx[i] * j;
			int ty = y + dy[i] * j;
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] != s[j])
				can = false;
		}
		if (can)
			return true;
	}
	return false;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf(" %c", &g[i][j]);
				g[i][j] = tolower(g[i][j]);
			}
		int q;
		scanf("%d", &q);
		while (q-- != 0) {
			scanf("%s", s);
			L = strlen(s);
			for (int i = 0; i < L; ++i)
				s[i] = tolower(s[i]);
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (g[i][j] == s[0] && check(i, j)) {
						printf("%d %d\n", i + 1, j + 1);
						i = n;
						j = m;
					}
		}
		if (t != 0)
			puts("");
	}
	return 0;
}
