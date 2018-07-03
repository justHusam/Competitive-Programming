#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dp[101][100], n, k;
const int M = 1e6;

int calc(int sum, int cnt) {
	if (cnt == k)
		return sum == n;
	if (dp[sum][cnt] != -1)
		return dp[sum][cnt];
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		if (sum + i > n)
			break;
		res = (res + calc(sum + i, cnt + 1)) % M;
	}
	return dp[sum][cnt] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &k) > 0 && n != 0) {
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
