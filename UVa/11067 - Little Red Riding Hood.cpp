#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, m;
ll dp[101][101];
bool no[101][101];

ll calc(int i, int j) {
	if (i == n && j == m)
		return 1;
	if (i > n || j > m || no[i][j])
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = calc(i + 1, j) + calc(i, j + 1);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && m != 0) {
		int q;
		scanf("%d", &q);
		memset(no, false, sizeof no);
		while (q-- != 0) {
			int x, y;
			scanf("%d%d", &x, &y);
			no[x][y] = true;
		}
		memset(dp, -1, sizeof dp);
		ll res = calc(0, 0);
		if (res == 0)
			puts("There is no path.");
		else if (res == 1)
			puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
		else
			printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n", res);
	}
	return 0;
}
