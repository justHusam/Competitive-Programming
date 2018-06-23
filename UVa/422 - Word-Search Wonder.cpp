#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n;
char g[111][111], s[111];
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[] = { -1, 1, 0, 0, -1, -1, 1, 1 };

bool check(int x, int y) {
	for (int i = 0; i < 8; ++i) {
		int can = 1, tx, ty;
		for (int j = 1; s[j] && can; ++j) {
			tx = x + dx[i] * j;
			ty = y + dy[i] * j;
			if (tx >= 0 && ty >= 0 && tx < n && ty < n && g[tx][ty] == s[j])
				continue;
			can = 0;
		}
		if (can) {
			printf("%d,%d %d,%d\n", x + 1, y + 1, tx + 1, ty + 1);
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", g[i]);
	while (scanf("%s", s) > 0 && s[0] != '0') {
		bool can = 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][j] == s[0] && check(i, j))
					can = 0, i = j = n;
		if (can)
			puts("Not found");
	}
	return 0;
}
