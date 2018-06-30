#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, N, g[9][9];
bool row[9][10], col[9][10], box[9][10];

bool calc(int x, int y) {
	if (x == N)
		return true;
	if (y == N)
		return calc(x + 1, 0);
	if (g[x][y])
		return calc(x, y + 1);
	for (int i = 1; i <= N; ++i)
		if (!row[x][i] && !col[y][i] && !box[x / n * n + y / n][i]) {
			row[x][i] = col[y][i] = box[x / n * n + y / n][i] = true;
			if (calc(x, y + 1)) {
				g[x][y] = i;
				return true;
			}
			row[x][i] = col[y][i] = box[x / n * n + y / n][i] = false;
		}
	return false;
}

int main(int argc, char **argv) {
	bool f = false;
	while (scanf("%d", &n) > 0) {
		if (f)
			puts("");
		f = true;
		N = n * n;
		for (int i = 0; i < N; ++i)
			for (int j = 1; j <= N; ++j)
				row[i][j] = col[i][j] = box[i][j] = false;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				scanf("%d", &g[i][j]);
				if (g[i][j] == 0)
					continue;
				row[i][g[i][j]] = col[j][g[i][j]] = box[i / n * n + j / n][g[i][j]] = true;
			}
		if (calc(0, 0))
			for (int i = 0; i < N; ++i, puts(""))
				for (int j = 0; j < N; ++j)
					printf("%s%d", j ? " " : "", g[i][j]);
		else
			puts("NO SOLUTION");
	}
	return 0;
}
