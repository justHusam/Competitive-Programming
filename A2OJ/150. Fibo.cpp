#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int dp[N];

int main(int argc, char **argv) {
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i < N; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	int n;
	while (scanf("%d", &n) > 0)
		printf("%d\n", dp[n]);
	return 0;
}
