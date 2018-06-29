#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 61;
int n, m, t;
int dp[N][N][N][N];
char x[N + 9], y[N + 9];

int calc(int a, int b, int c, int d) {
	if (a > b || c > d)
		return 0;
	int &res = dp[a][b][c][d];
	if (res != -1)
		return res;
	if (a == b) {
		for (int i = c; i <= d; ++i)
			if (y[i] == x[a])
				return res = 1;
		return res = 0;
	}
	if (c == d) {
		for (int i = a; i <= b; ++i)
			if (x[i] == y[c])
				return res = 1;
		return res = 0;
	}
	if (x[a] == x[b] && y[c] == y[d] && x[a] == y[c])
		return res = calc(a + 1, b - 1, c + 1, d - 1) + 2;
	res = max(res, calc(a + 1, b, c, d));
	res = max(res, calc(a, b - 1, c, d));
	res = max(res, calc(a, b, c + 1, d));
	res = max(res, calc(a, b, c, d - 1));
	return res;
}

int main(int argc, char **argv) {
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%s", x, y);
		n = strlen(x);
		m = strlen(y);
		static int k = 1;
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", k++, calc(0, n - 1, 0, m - 1));
	}
	return 0;
}
