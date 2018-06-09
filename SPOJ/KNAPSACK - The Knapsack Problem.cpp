#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 2001;
int n, cap, dp[N][N], v[N], g[N];

inline int calc(int with, int idx) {
	if (with < 0)
		return -(2e9);
	if (idx == n)
		return 0;
	if (dp[with][idx] != -1)
		return dp[with][idx];
	int a = calc(with, idx + 1);
	int b = calc(with - v[idx], idx + 1) + g[idx];
	return dp[with][idx] = max(a, b);
}

int main(int argc, char **argv) {
	scanf("%d%d", &cap, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", v + i, g + i);
	memset(dp, -1, sizeof dp);
	printf("%d\n", calc(cap, 0));
	return 0;
}
