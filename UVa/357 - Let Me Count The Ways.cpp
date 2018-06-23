#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long int ll;

ll dp[30002][5];
int v[] = { 1, 5, 10, 25, 50 };

ll calc(int r, int i) {
	if (r < 0 || i == 5)
		return 0;
	if (r == 0)
		return 1;
	if (dp[r][i] != -1)
		return dp[r][i];
	ll res = 0;
	for (int j = i; j < 5; ++j)
		res += calc(r - v[j], j);
	return dp[r][i] = res;
}

int main(int argc, char **argv) {
	int n;
	memset(dp, -1, sizeof dp);
	while (scanf("%d", &n) > 0) {
		ll res = calc(n, 0);
		if (res == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", calc(n, 0), n);
	}
	return 0;
}
