#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3 + 5;
char s[N];
int n, dp[N][N];

int calc(int i, int j) {
	if (i >= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s[i] == s[j])
		return dp[i][j] = calc(i + 1, j - 1);
	int a = calc(i + 1, j) + 1;
	int b = calc(i, j - 1) + 1;
	return dp[i][j] = min(a, b);
}

inline void path(int i, int j) {
	if (i == j) {
		putchar(s[i]);
		return;
	}
	if (i > j)
		return;
	if (s[i] == s[j]) {
		putchar(s[i]);
		path(i + 1, j - 1);
		putchar(s[j]);
		return;
	}
	int a = calc(i + 1, j) + 1;
	int b = calc(i, j - 1) + 1;
	if (a < b) {
		putchar(s[i]);
		path(i + 1, j);
		putchar(s[i]);
		return;
	}
	putchar(s[j]);
	path(i, j - 1);
	putchar(s[j]);
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0) {
		n = strlen(s);
		memset(dp, -1, sizeof dp);
		printf("%d ", calc(0, n - 1));
		path(0, n - 1);
		putchar('\n');
	}
	return 0;
}
