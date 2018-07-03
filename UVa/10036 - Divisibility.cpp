#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 10000;
int n, k, v[N], dp[N][101];

bool calc(int i, int m) {
	if (i == n)
		return !m;
	if (dp[i][m] != -1)
		return dp[i][m];
	return dp[i][m] = calc(i + 1, (m + v[i]) % k) || calc(i + 1, (m - v[i]) % k);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		memset(dp, -1, sizeof dp);
		if (calc(0, 0))
			puts("Divisible");
		else
			puts("Not divisible");
	}
	return 0;
}
