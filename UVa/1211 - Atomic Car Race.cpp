#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int n, a[N], r, cum[1000001];
double b, v, e, f, cost[1000001], dp[N][N];

double calc(int at, int last, int w) {
	if (at == n)
		return 0;
	double &res = dp[at][last];
	if (res == res)
		return res;
	res = calc(at + 1, last, w + a[at + 1] - a[at]) + cost[w + a[at + 1] - a[at] - 1] - cost[w - 1];
	res = min(res, calc(at + 1, at, a[at + 1] - a[at]) + b + cost[a[at + 1] - a[at] - 1]);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			cum[i] = cum[i - 1] + a[i];
		}
		scanf("%lf%d%lf%lf%lf", &b, &r, &v, &e, &f);
		for (int i = 0; i <= cum[n]; ++i) {
			if (i < r)
				cost[i] = 1.0 / (v - f * (r - i));
			else
				cost[i] = 1.0 / (v - e * (i - r));
			if (i != 0)
				cost[i] += cost[i - 1];
		}
		memset(dp, -1, sizeof dp);
		printf("%.4lf\n", calc(1, 0, a[1]) + cost[a[1] - 1]);
	}
	return 0;
}
