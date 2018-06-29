#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101, M = 1000007;
int n, dp[N][N];
char g[N][N];

int calc(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n || g[x][y] == 'B')
		return 0;
	if (x == 0)
		return 1;
	int &res = dp[x][y];
	if (res != -1)
		return res;
	res = 0;
	if (x - 1 >= 0 && y + 1 < n) {
		if (g[x - 1][y + 1] == 'B')
			res += calc(x - 2, y + 2);
		else
			res += calc(x - 1, y + 1);
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (g[x - 1][y - 1] == 'B')
			res += calc(x - 2, y - 2);
		else
			res += calc(x - 1, y - 1);
	}
	res %= M;
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		int x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == 'W')
					x = i, y = j;
			}
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", cas++, calc(x, y));
	}
	return 0;
}
