#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, k, s;
int dp[21][11][160], v[100];

inline int calc(int i, int w, int sum) {
	if (i == n)
		return w == k && sum == s;
	if (sum > s)
		return 0;
	if (dp[i][w][sum] != -1)
		return dp[i][w][sum];
	int a = calc(i + 1, w + 1, sum + v[i]);
	int b = calc(i + 1, w, sum);
	return dp[i][w][sum] = a + b;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &k, &s) && n != 0) {
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; ++i)
			v[i] = i + 1;
		printf("%d\n", calc(0, 0, 0));
	}
	return 0;
}
