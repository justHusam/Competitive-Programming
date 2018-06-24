#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 89;
char x[N], y[N];
int dp[N][N], n, m, idx;

int calc(int i, int j) {
	if (i == n && j == m)
		return 0;
	if (i > n || j > m)
		return 2e9;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = calc(i + 1, j + 1);
	int a = calc(i, j + 1) + 1; // insert
	int b = calc(i + 1, j) + 1; // delete
	int c = calc(i + 1, j + 1) + 1; // replace
	return dp[i][j] = min(a, min(b, c));
}

void path(int i, int j, int inc, int dec) {
	if (i == n && j == m)
		return;
	if (x[i] == y[j]) {
		path(i + 1, j + 1, inc, dec);
		return;
	}
	printf("%d ", idx++);
	int a = calc(i, j + 1) + 1; // insert
	int b = calc(i + 1, j) + 1; // delete
	int c = calc(i + 1, j + 1) + 1; // replace
	int mn = min(a, min(b, c));
	int len = i + 1;
	len += inc;
	len -= dec;
	if (a == mn) {
		printf("Insert %d,%c\n", len, y[j]);
		path(i, j + 1, inc + 1, dec);
		return;
	}
	if (b == mn) {
		printf("Delete %d\n", len);
		path(i + 1, j, inc, dec + 1);
		return;
	}
	printf("Replace %d,%c\n", len, y[j]);
	path(i + 1, j + 1, inc, dec);
}

int main(int argc, char **argv) {
	bool newLine = false;
	while (gets(x) > 0) {
		if (newLine)
			puts("");
		newLine = true;
		gets(y);
		n = strlen(x);
		m = strlen(y);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
		idx = 1;
		path(0, 0, 0, 0);
	}
	return 0;
}
