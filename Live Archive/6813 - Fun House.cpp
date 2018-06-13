#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 21;
int n, m;
char g[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
pair<int, int> E;

void go(int x, int y, int at) {
	if (g[x][y] == 'x') {
		E = make_pair(x, y);
		return;
	}
	if (g[x][y] == '/') {
		if (at == 0)
			go(x - 1, y, 3);
		else if (at == 1)
			go(x + 1, y, 2);
		else if (at == 2)
			go(x, y - 1, 1);
		else
			go(x, y + 1, 0);
		return;
	}
	if (g[x][y] == '\\') {
		if (at == 0)
			go(x + 1, y, 2);
		else if (at == 1)
			go(x - 1, y, 3);
		else if (at == 2)
			go(x, y + 1, 0);
		else
			go(x, y - 1, 1);
		return;
	}
	go(x + dx[at], y + dy[at], at);
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &m, &n) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		int x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (g[i][j] == '*') {
					x = i;
					y = j;
					i = j = N;
				}
		if (x == 0)
			go(x, y, 2);
		else if (y == 0)
			go(x, y, 0);
		else if (y == m - 1)
			go(x, y, 1);
		else
			go(x, y, 3);
		g[E.first][E.second] = '&';
		printf("HOUSE %d\n", cas++);
		for (int i = 0; i < n; ++i)
			puts(g[i]);
	}
	return 0;
}
