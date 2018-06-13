#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, r, c, k, g[N][N], v[N], temp[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

int main(int argc, char **argv) {
	while (scanf("%d%d%d%d", &n, &r, &c, &k) && (n || r || c || k)) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				scanf("%d", &g[i][j]);
		for (int i = 0; i < n; ++i)
			v[i] = (i + 1) % n;
		while (k-- != 0) {
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j)
					temp[i][j] = g[i][j];
			for (int x = 0; x < r; ++x)
				for (int y = 0; y < c; ++y)
					for (int i = 0; i < 4; ++i) {
						int tx = x + dx[i];
						int ty = y + dy[i];
						if (tx < 0 || ty < 0 || tx >= r || ty >= c || g[tx][ty] != v[g[x][y]])
							continue;
						temp[tx][ty] = g[x][y];
					}
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j)
					g[i][j] = temp[i][j];
		}
		for (int i = 0; i < r; ++i, puts(""))
			for (int j = 0; j < c; ++j)
				printf("%s%d", j ? " " : "", g[i][j]);
	}
	return 0;
}
