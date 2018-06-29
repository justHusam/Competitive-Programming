#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n;
char g[15][15];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

char calc(int x, int y) {
	bool vis[26] = { };
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < n && ty < n && g[tx][ty] != '.')
			vis[g[tx][ty] - 'A'] = 1;
	}
	for (int a = 0; a < 26; ++a)
		if (!vis[a])
			return a + 'A';
	return '?';
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][j] == '.')
					g[i][j] = calc(i, j);
		printf("Case %d:\n", k++);
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < n; ++j)
				putchar(g[i][j]);
	}
	return 0;
}
