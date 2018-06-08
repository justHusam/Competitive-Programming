#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
int n, a[N];
ll dp[N];

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		dp[0] = a[0];
		dp[1] = max(a[0], a[1]);
		for (int i = 2; i < n; ++i)
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		printf("Case %d: %lld\n", k++, dp[n - 1]);
	}
	return 0;
}
