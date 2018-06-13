#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, vis[17][18][1 << 17], vs;
ll dp[17][18][1 << 17];

ll calc(int i, int k, int msk) {
	if (msk == (1 << n) - 1)
		return 1;
	if (i == n)
		return 0;
	ll &res = dp[i][k][msk];
	if (vis[i][k][msk] == vs)
		return res;
	vis[i][k][msk] = vs;
	res = 0;
	for (int j = 0; j < n; ++j) {
		if (k != 0 && j == i)
			continue;
		res += calc(i + 1, max(k - 1, 0), msk | (1 << j));
	}
	return res;
}

int main(int argc, char **argv) {
	int t, cas;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &cas, &n, &k);
		++vs;
		printf("%d %lld\n", cas, calc(0, k, 0));
	}
	return 0;
}
