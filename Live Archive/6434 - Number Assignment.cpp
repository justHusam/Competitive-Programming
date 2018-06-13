#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, a[N];
ll dp[N][N];

ll calc(int s, int w) {
	if (s == n)
		return (w != m) * 1e15;
	if (w >= m)
		return 1e15;
	ll &res = dp[s][w];
	if (res != -1)
		return res;
	res = 1e15;
	for (int i = s; i < n; ++i)
		res = min(res, calc(i + 1, w + 1) + a[i] - a[s]);
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %lld\n", cas++, calc(0, 0));
	}
	return 0;
}
