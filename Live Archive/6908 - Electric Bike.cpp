#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, k, p, a[N], add[] = { 0, 4, 8, 11 }, cum[N + 1], dp[N][4][11][51], vis[N][4][11][51], vs;

int calc(int at, int lst, int k, int E) {
	if (at == n)
		return 0;
	int &res = dp[at][lst][k][E];
	if (vis[at][lst][k][E] == vs)
		return res;
	vis[at][lst][k][E] = vs;
	res = 2e9;
	bool need = true;
	for (int i = 0; i < 4; ++i) {
		if (i == lst) {
			if (i <= E) {
				res = min(res, calc(at + 1, i, k, E - i) + max(0, a[at] - add[i]));
				need = false;
			}
		} else if (k > 0 && i <= E) {
			res = min(res, calc(at + 1, i, k - 1, E - i) + max(0, a[at] - add[i]));
			need = false;
		}
	}
	if (need)
		res = cum[n] - cum[at];
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &n, &k, &p);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			cum[i + 1] = cum[i] + a[i];
		}
		++vs;
		printf("Case #%d: %d\n", cas++, calc(0, 0, k, p));
	}
	return 0;
}
