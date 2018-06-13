#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, d, dp[2000][21], cum[2001];

inline int get(int s, int e) {
	int v = cum[e + 1] - cum[s];
	int m = v % 10;
	v /= 10;
	if (m >= 5)
		++v;
	return v * 10;
}

int calc(int at, int d) {
	if (at == n)
		return 0;
	int &res = dp[at][d];
	if (res != -1)
		return res;
	if (d == 0)
		return res = get(at, n - 1);
	res = 1e9;
	for (int i = at; i < n; ++i)
		res = min(res, calc(i + 1, d - 1) + get(at, i));
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &d) > 0) {
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			cum[i] = cum[i - 1] + x;
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, d));
	}
	return 0;
}
