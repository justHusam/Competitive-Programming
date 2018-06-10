#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, g;
ll dp[65][10];

ll calc(int c, int d) {
	if (c == n)
		return 1;
	if (dp[c][d] != -1)
		return dp[c][d];
	ll res = 0;
	for (int i = d; i <= 9; ++i)
		res += calc(c + 1, i);
	return dp[c][d] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &g, &n);
		memset(dp, -1, sizeof dp);
		printf("%d %lld\n", g, calc(0, 0));
	}
	return 0;
}
