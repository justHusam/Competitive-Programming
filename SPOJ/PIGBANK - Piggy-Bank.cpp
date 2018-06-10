#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */
typedef long long ll;

const ll oo = 1e15;
ll dp[10001][500];
int x, y, n, W[500], P[500];

ll calc(int rem, int at) {
	if (rem == 0)
		return 0;
	if (rem < 0 || at == n)
		return oo;
	if (dp[rem][at] != -1)
		return dp[rem][at];
	ll a = calc(rem - W[at], at) + P[at];
	ll b = calc(rem, at + 1);
	return dp[rem][at] = min(a, b);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d%d", &x, &y, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &P[i], &W[i]);
		memset(dp, -1, sizeof dp);
		ll r = calc(y - x, 0);
		if (r == oo)
			puts("This is impossible.");
		else
			printf("The minimum amount of money in the piggy-bank is %lld.\n", r);
	}
	return 0;
}
