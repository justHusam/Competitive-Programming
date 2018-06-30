#include<bits/stdc++.h>
using namespace std;

char g[11][11][2];
int n, dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 }, dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

int calc(int x, int y) {
	int res = 0;
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < n && ty < n)
			res += g[tx][ty][0] == '*';
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	bool newLine = false;
	scanf("%d", &t);
	while (t-- != 0) {
		if (newLine)
			puts("");
		newLine = true;
		scanf("%d", &n);
		for (int k = 0; k < 2; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					scanf(" %c", &g[i][j][k]);
		bool can = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][j][0] == '*' && g[i][j][1] == 'x') {
					can = false;
					i = j = n;
				}
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < n; ++j)
				if (g[i][j][1] == 'x' && g[i][j][0] == '.')
					putchar(calc(i, j) + '0');
				else
					putchar(g[i][j][can]);
	}
	return 0;
}
