#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, dp[31], dp1[31];

int calc(int n);

int calc1(int n) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	if (dp1[n] == -1)
		dp1[n] = calc(n - 1) + calc1(n - 2);
	return dp1[n];
}

int calc(int n) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	if (dp[n] == -1)
		dp[n] = calc(n - 2) + 2 * calc1(n - 1);
	return dp[n];
}

int main(int argc, char **argv) {
	memset(dp, -1, sizeof dp);
	memset(dp1, -1, sizeof dp1);
	while (scanf("%d", &n) && n != -1) {
		if ((n & 1) == 1)
			puts("0");
		else
			printf("%d\n", calc(n));
	}
	return 0;
}
