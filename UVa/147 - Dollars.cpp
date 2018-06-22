#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

ll dp[300 * 100 + 102][12];
int v[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

ll calc(int r, int i) {
	if (r < 0)
		return 0;
	if (!r)
		return 1;
	if (dp[r][i] != -1)
		return dp[r][i];
	ll res = 0;
	for (int j = i; j < 11; ++j)
		res += calc(r - v[j], j);
	return dp[r][i] = res;
}

int main(int argc, char **argv) {
	double n;
	memset(dp, -1, sizeof dp);
	while (scanf("%lf", &n) && n != 0) {
		int v = (n + 1e-9) * 100;
		printf("%6.2lf%17lld\n", n, calc(v, 0));
	}
	return 0;
}
