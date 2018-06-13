#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char g[9][10];
bool visR[9][10], visC[9][10], visS[3][3][10];

bool calc(int x, int y) {
	if (x == 9)
		return true;
	if (y == 9)
		return calc(x + 1, 0);
	if (g[x][y] != '0')
		return calc(x, y + 1);
	for (int i = 1; i <= 9; ++i)
		if (!visR[x][i] && !visC[y][i] && !visS[x / 3][y / 3][i]) {
			visR[x][i] = visC[y][i] = visS[x / 3][y / 3][i] = true;
			if (calc(x, y + 1)) {
				g[x][y] = char(i + '0');
				return true;
			}
			visR[x][i] = visC[y][i] = visS[x / 3][y / 3][i] = false;
		}
	return false;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		memset(visR, false, sizeof visR);
		memset(visC, false, sizeof visC);
		memset(visS, false, sizeof visS);
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				scanf(" %c", &g[i][j]);
				int d = g[i][j] - '0';
				visR[i][d] = visC[j][d] = visS[i / 3][j / 3][d] = true;
			}
		calc(0, 0);
		for (int i = 0; i < 9; ++i)
			puts(g[i]);
	}
	return 0;
}
