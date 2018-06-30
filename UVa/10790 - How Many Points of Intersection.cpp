#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e4;
ll dp[N];

int main(int argc, char **argv) {
	int cas = 1, a, b;
	while (scanf("%d%d", &a, &b) > 0 && a + b > 0) {
		dp[0] = 0;
		for (int i = 1; i < a; ++i)
			dp[i] = dp[i - 1] + ((ll) b * (b - 1) / 2) * i;
		printf("Case %d: %lld\n", cas++, dp[a - 1]);
	}
	return 0;
}
