#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3 + 5;
char x[N], y[N];
int dp[N][N], n, m;

int calc(int i, int j) {
	if (i == n && j == m)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = calc(i + 1, j + 1);
	if (i == n)
		return dp[i][j] = calc(i, j + 1) + 30;
	if (j == m)
		return dp[i][j] = calc(i + 1, j) + 15;
	int a = calc(i + 1, j) + 15;
	int b = calc(i, j + 1) + 30;
	return dp[i][j] = min(a, b);
}

int main(int argc, char **argv) {
	while (scanf("%s", x) > 0) {
		if (x[0] == '#')
			break;
		scanf("%s", y);
		memset(dp, -1, sizeof dp);
		n = strlen(x);
		m = strlen(y);
		cout << calc(0, 0) << "\n";
	}
	return 0;
}
