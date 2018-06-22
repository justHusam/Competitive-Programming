#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 25;
char x[N], y[N];
int n, m, dp[N][N];

inline int calc(int i, int j) {
	if (i == n && j == m)
		return 0;
	if (i > n || j > m)
		return 2e9;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = calc(i + 1, j + 1);
	int a = calc(i + 1, j) + 1;
	int b = calc(i, j + 1) + 1;
	int c = calc(i + 1, j + 1) + 1;
	return dp[i][j] = min(a, min(b, c));
}

inline void put(int i) {
	if (i < 10)
		putchar('0');
	printf("%d", i);
}

inline void path(int i, int j, int inc, int dec) {
	if (i == n && j == m) {
		putchar('E');
		return;
	}
	if (x[i] == y[j]) {
		path(i + 1, j + 1, inc, dec);
		return;
	}
	int a = calc(i + 1, j) + 1;
	int b = calc(i, j + 1) + 1;
	int c = calc(i + 1, j + 1) + 1;
	int m = min(a, min(b, c));
	int len = i + 1 + inc - dec;
	if (a == m) {
		putchar('D');
		putchar(x[i]);
		put(len);
		path(i + 1, j, inc, dec + 1);
		return;
	}
	if (b == m) {
		putchar('I');
		putchar(y[j]);
		put(len);
		path(i, j + 1, inc + 1, dec);
		return;
	}
	putchar('C');
	putchar(y[j]);
	put(len);
	path(i + 1, j + 1, inc, dec);
}

int main(int argc, char **argv) {
	while (scanf("%s", x) > 0 && x[0] != '#') {
		scanf("%s", y);
		n = strlen(x);
		m = strlen(y);
		memset(dp, -1, sizeof dp);
		calc(0, 0);
		path(0, 0, 0, 0);
		putchar('\n');
	}
	return 0;
}
