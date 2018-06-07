#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int g[N][N];
bool visR[N][10], visC[N][10], visD[3][3][10];

bool calc(int x, int y) {
	if (x == N)
		return true;
	if (y == N)
		return calc(x + 1, 0);
	if (g[x][y])
		return calc(x, y + 1);
	for (int i = 1; i <= N; ++i) {
		if (!visR[x][i] && !visC[y][i] && !visD[x / 3][y / 3][i]) {
			visR[x][i] = visC[y][i] = visD[x / 3][y / 3][i] = true;
			if (calc(x, y + 1)) {
				g[x][y] = i;
				return true;
			}
			visR[x][i] = visC[y][i] = visD[x / 3][y / 3][i] = false;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(visR, false, sizeof visR);
		memset(visC, false, sizeof visC);
		memset(visD, false, sizeof visD);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				scanf("%d", &g[i][j]);
				if (g[i][j])
					visR[i][g[i][j]] = visC[j][g[i][j]] = visD[i / 3][j / 3][g[i][j]] = true;
			}
		if (calc(0, 0)) {
			for (int i = 0; i < N; ++i, puts(""))
				for (int j = 0; j < N; ++j)
					printf("%s%d", j ? " " : "", g[i][j]);
		} else
			puts("No solution");
	}
	return 0;
}
