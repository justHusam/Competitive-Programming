#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 52;
int n;
ll dp[N][2];

int main(int argc, char **argv) {
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < N; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		printf("Scenario #%d:\n%lld\n\n", cas++, dp[n][0] + dp[n][1]);
	}
	return 0;
}
