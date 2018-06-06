#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 2e7 + 1;
int dp[N];

int calc(int r) {
	if (r == 1)
		return 0;
	if (r < 1)
		return 2e9;
	if (dp[r] != -1)
		return dp[r];
	int res = 2e9;
	if (r % 3 == 0)
		res = min(res, calc(r / 3) + 1);
	if (r % 2 == 0)
		res = min(res, calc(r / 2) + 1);
	for (int i = 1; i < 4; ++i) {
		int t = r - i;
		if (t % 3 == 0)
			res = min(res, calc(t / 3) + i + 1);
		if (t % 2 == 0)
			res = min(res, calc(t / 2) + i + 1);
	}
	return dp[r] = res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	memset(dp, -1, sizeof dp);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", ++k, calc(n));
	}
	return 0;
}
