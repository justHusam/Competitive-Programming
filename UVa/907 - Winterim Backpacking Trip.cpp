#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, a[602];
int cum[602], dp[602][301];

int calc(int i, int w) {
	if (i == n)
		return w == k ? a[n] : 2e9;
	if (w == k)
		return cum[n + 1] - cum[i];
	int &res = dp[i][w];
	if (res != -1)
		return res;
	res = calc(i, w + 1);
	for (int j = i; j < n; ++j)
		res = min(res, max(cum[j + 1] - cum[i], calc(j + 1, w + 1)));
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &k) > 0) {
		for (int i = 0; i <= n; ++i) {
			scanf("%d", &a[i]);
			cum[i + 1] = cum[i] + a[i];
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
