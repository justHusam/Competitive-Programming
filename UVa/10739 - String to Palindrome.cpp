#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1005;
int n, dp[N][N];
char s[N];

int calc(int i, int j) {
	if (i == j || i - 1 == j)
		return 0;
	if (i >= j)
		return 2e9;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s[i] == s[j])
		return dp[i][j] = calc(i + 1, j - 1);
	int res = 2e9;
	res = min(res, calc(i + 1, j) + 1);
	res = min(res, calc(i, j - 1) + 1);
	res = min(res, calc(i + 1, j - 1) + 1);
	return dp[i][j] = res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		n = strlen(s);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", k++, calc(0, n - 1));
	}
	return 0;
}
