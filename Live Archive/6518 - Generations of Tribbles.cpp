#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	ll dp[70] = { };
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 70; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}
