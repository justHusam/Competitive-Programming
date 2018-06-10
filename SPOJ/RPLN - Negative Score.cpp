#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, q, a[N], dp[N][18];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			dp[i][0] = a[i];
		}
		for (int j = 1; (1 << j) <= n; ++j)
			for (int i = 0; i + (1 << j) <= n; ++i)
				dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		printf("Scenario #%d:\n", cas++);
		while (q-- != 0) {
			int l, r, log = 0;
			scanf("%d%d", &l, &r);
			--l;
			--r;
			while ((1 << log) <= r - l + 1)
				++log;
			--log;
			printf("%d\n", min(dp[l][log], dp[r - (1 << log) + 1][log]));
		}
	}
	return 0;
}
