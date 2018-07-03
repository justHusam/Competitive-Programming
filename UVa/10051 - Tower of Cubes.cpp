#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 500, M = 105;
int n, v[N][6], dp[N][M], dr[] = { 1, 0, 3, 2, 5, 4 }, k;
string ptr[] = { "front", "back", "left", "right", "top", "bottom" };

int calc(int at, int col) {
	if (at == n)
		return 0;
	if (dp[at][col] != -1)
		return dp[at][col];
	int res = calc(at + 1, col);
	for (int i = 0; i < 6; ++i)
		if (v[at][i] == col || col == 103)
			res = max(res, calc(at + 1, v[at][dr[i]]) + 1);
	return dp[at][col] = res;
}

void path(int at, int col) {
	if (at == n)
		return;
	int r1 = calc(at + 1, col), r2 = 0, p;
	for (int i = 0; i < 6; ++i)
		if ((v[at][i] == col || col == 103) && calc(at + 1, v[at][dr[i]]) + 1 > r2) {
			r2 = calc(at + 1, v[at][dr[i]]) + 1;
			p = i;
		}
	if (r1 >= r2)
		path(at + 1, col);
	else {
		printf("%d %s\n", at + 1, ptr[p].c_str());
		path(at + 1, v[at][dr[p]]);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		if (k != 0)
			puts("");
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 6; ++j)
				scanf("%d", &v[i][j]);
		memset(dp, -1, sizeof dp);
		printf("Case #%d\n%d\n", ++k, calc(0, 103));
		path(0, 103);
	}
	return 0;
}
