#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef unsigned long long ll;

int dp[201][201], n;
char s[205];

int calc(int i, int j, int o, int z) {
	if (i == n)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int res = 0, oo = o + (s[i] == '1'), zz = z + (s[i] == '0');
	res = calc(i + 1, j, oo, zz);
	if (oo > zz)
		res = max(res, calc(i + 1, i + 1, 0, 0) + i - j + 1);
	res = max(res, calc(i + 1, i + 1, 0, 0));
	return dp[i][j] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%s", &n, s);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, 0, 0));
	}
	return 0;
}
