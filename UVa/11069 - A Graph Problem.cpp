#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int dp[80], n;

int calc(int at) {
	if (at > n)
		return 0;
	if (dp[at] != -1)
		return dp[at];
	int res = calc(at + 2) + calc(at + 3);
	if (res == 0)
		++res;
	return dp[at] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(1) + calc(2));
	}
	return 0;
}
