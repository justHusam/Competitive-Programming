#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char g[101][101];
int n, m, dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 }, dy[] = { -1, 1, 0, 0, -1, 1, -1, 1 };

int calc(int x, int y) {
	int res = 0;
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < n && ty < m && g[tx][ty] == '*')
			++res;
	}
	return res;
}

int main(int argc, char **argv) {
	int k = 0;
	while (scanf("%d%d", &n, &m) > 0 && n + m != 0) {
		if (k != 0)
			puts("");
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		printf("Field #%d:\n", ++k);
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < m; ++j)
				if (g[i][j] == '.')
					printf("%d", calc(i, j));
				else
					putchar('*');
	}
	return 0;
}
