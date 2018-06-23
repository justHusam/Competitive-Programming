#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 501;
int n, k, a[N];
ll dp[N][N], cum[N];

ll calc(int at, int w) {
	if (at == n)
		return (w != k) * 2e15;
	if (w == k)
		return 2e15;
	ll &res = dp[at][w];
	if (res != -1)
		return res;
	res = 2e15;
	for (int i = at; i < n; ++i)
		res = min(res, max(calc(i + 1, w + 1), cum[i + 1] - cum[at]));
	return res;
}

void path(int at, int w) {
	if (at == n)
		return;
	if (w != 0)
		printf(" /");
	for (int i = at; i < n; ++i) {
		printf("%s%d", i ? " " : "", a[i]);
		if (max(calc(i + 1, w + 1), cum[i + 1] - cum[at]) <= calc(0, 0)) {
			path(i + 1, w + 1);
			break;
		}
	}
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			cum[i + 1] = cum[i] + a[i];
		}
		memset(dp, -1, sizeof dp);
		calc(0, 0);
		path(0, 0);
		puts("");
	}
	return 0;
}
