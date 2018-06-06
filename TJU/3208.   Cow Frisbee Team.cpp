#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 2e3, F = 1e3 + 1, M = 1e8;
int n, v[N], dp[N][F][2], f;

inline int calc(int idx, int mod, bool st) {
	if (idx == n)
		return st && !mod;
	if (dp[idx][mod][st] != -1)
		return dp[idx][mod][st];
	int a = calc(idx + 1, mod, st);
	int b = calc(idx + 1, (mod + v[idx]) % f, 1);
	return dp[idx][mod][st] = (a % M + b % M) % M;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &f) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, 0));
	}
	return 0;
}
