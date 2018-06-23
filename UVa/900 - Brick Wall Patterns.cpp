#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 51;
ll dp[N];

int main(int argc, char **argv) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < N; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	int n;
	while (scanf("%d", &n) > 0 && n != 0)
		printf("%lld\n", dp[n]);
	return 0;
}
