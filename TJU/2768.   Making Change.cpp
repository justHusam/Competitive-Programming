#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, dp[1001][10], v[10], c;

inline int calc(int with, int idx) {
	if (!with)
		return 0;
	if (with < 0)
		return 2e9;
	if (dp[with][idx] != -1)
		return dp[with][idx];
	int res = 2e9;
	for (int i = idx; i < n; ++i)
		res = min(res, calc(with - v[i], i) + 1);
	return dp[with][idx] = res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &c, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", v + i);
	memset(dp, -1, sizeof dp);
	printf("%d\n", calc(c, 0));
	return 0;
}
