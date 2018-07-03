#include <bits/stdc++.h>
using namespace std;

/*
 *  * You got a dream, you gotta protect it.
 */

unsigned int g[200];
int dp[200][21][11], n, q, m, d;

int get(int a, int b) {
	return (a % b + b) % b;
}

inline int calc(int at, int mod, int cnt) {
	if (cnt == m)
		return !mod;
	if (at == n)
		return 0;
	if (dp[at][mod][cnt] != -1)
		return dp[at][mod][cnt];
	int a = calc(at + 1, mod, cnt);
	int b = calc(at + 1, get(mod + g[at], d), cnt + 1);
	return dp[at][mod][cnt] = a + b;
}

int main(int argc, char **argv) {
	int k = 1;
	while (scanf("%d%d", &n, &q) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%u", &g[i]);
		printf("SET %d:\n", k++);
		for (int i = 1; i <= q; ++i) {
			scanf("%d%d", &d, &m);
			memset(dp, -1, sizeof dp);
			printf("QUERY %d: %d\n", i, calc(0, 0, 0));
		}
	}
	return 0;
}
