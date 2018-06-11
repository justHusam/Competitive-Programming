#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000;
int n, m, g[N][N], s[N][N], e[N][N];
char out[] = { 'N', 'E', 'S', 'W' }, ch;

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf(" %c", &ch);
			for (int k = 0; k < 4; ++k)
				if (ch == out[k]) {
					g[i][j] = k;
					break;
				}
		}
	int q;
	scanf("%d", &q);
	while (q-- != 0) {
		scanf(" %c", &ch);
		if (ch == 'C') {
			int x1, y1, x2, y2, v;
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
			--x1;
			--y1;
			--x2;
			--y2;
			if (v == 0)
				v = 1;
			else
				v = -1;
			while (x1 <= x2) {
				s[x1][y1] += v;
				e[x1][y2] += v;
				++x1;
			}
		} else {
			int x, y, add = 0;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			for (int i = 0; i < m; ++i) {
				add += s[x][i];
				g[x][i] += add;
				add -= e[x][i];
				s[x][i] = e[x][i] = 0;
			}
			printf("%c\n", out[(g[x][y] % 4 + 4) % 4]);
		}
	}
	return 0;
}
