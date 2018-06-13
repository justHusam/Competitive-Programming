#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001, M = 1e9 + 7;
int n, k;
ll dp[N][N];

ll calc(int z, int k) {
	if (k == 0)
		return z == n;
	ll &res = dp[z][k];
	if (res != -1)
		return res;
	int o = n - z;
	res = 0;
	if (z != 0)
		res = (res + calc(z - 1, k - 1) * z) % M;
	if (o != 0)
		res = (res + calc(z + 1, k - 1) * o) % M;
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &k);
		int z = 0;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			if (x == 0)
				++z;
		}
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %lld\n", cas++, calc(z, k));
	}
	return 0;
}
