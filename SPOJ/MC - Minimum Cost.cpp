#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3;
int n, m, dp[N][N];
char x[N + 1], y[N + 1];

inline int calc(int i, int j) {
	if (i == n)
		return (m - j) * 30;
	if (j == m)
		return (n - i) * 15;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = calc(i + 1, j + 1);
	int a = calc(i + 1, j) + 15;
	int b = calc(i, j + 1) + 30;
	return dp[i][j] = min(a, b);
}

int main(int argc, char **argv) {
	while (scanf("%s", x) && x[0] != '#') {
		scanf("%s", y);
		n = strlen(x);
		m = strlen(y);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
