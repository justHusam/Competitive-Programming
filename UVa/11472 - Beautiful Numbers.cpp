#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int M = 1e9 + 7;
int n, m, dp[1 << 10][101][10], all;

int calc(int mask, int with, int last) {
	if (with == 0)
		return mask == all;
	if (dp[mask][with][last] != -1)
		return dp[mask][with][last];
	int res = mask == all;
	if (last - 1 >= 0)
		res += calc(mask | (1 << (last - 1)), with - 1, last - 1) % M;
	if (last + 1 < n)
		res += calc(mask | (1 << (last + 1)), with - 1, last + 1) % M;
	return dp[mask][with][last] = res % M;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		if (m == 0 || m < n) {
			puts("0");
			continue;
		}
		all = (1 << n) - 1;
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 1; i < n; ++i) {
			res += calc(0 | (1 << i), m - 1, i);
			res %= M;
		}
		printf("%d\n", res);
	}
	return 0;
}
