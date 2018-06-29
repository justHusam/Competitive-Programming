#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dp[7490][5], n, g[] = { 1, 5, 10, 25, 50 };

int calc(int rem, int idx) {
	if (rem < 0)
		return 0;
	if (!rem)
		return 1;
	if (dp[rem][idx] != -1)
		return dp[rem][idx];
	int res = 0;
	for (int i = idx; i < 5; ++i)
		res += calc(rem - g[i], i);
	return dp[rem][idx] = res;
}

int main(int argc, char **argv) {
	memset(dp, -1, sizeof dp);
	while (scanf("%d", &n) > 0)
		printf("%d\n", calc(n, 0));
	return 0;
}
