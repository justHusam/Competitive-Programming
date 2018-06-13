#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
int n, a[N], b[N];
ll dp[N][30][2];

ll calc(int at, int w, bool f) {
	if (at >= n)
		return 0;
	ll &res = dp[at][w][f];
	if (res != -1)
		return res;
	res = 2e15;
	if (w != 0) {
		if (f)
			res = calc(at + 1, w - 1, f);
		else {
			res = min(res, calc(at + 1, w - 1, f) + b[at] * 2);
			res = min(res, calc(at + 1, w - 1, f) + 6);
			if (w - 1 > 6)
				res = min(res, calc(at + 7, w - 7, false) + 36);
			else
				res = min(res, calc(at + 1, 6, true) + 36);
			res = min(res, calc(at + 1, max(29, w - 1), true) + 90);
		}
	} else {
		res = min(res, calc(at + 1, 0, false) + a[at] + b[at] * 2); // 1
		res = min(res, calc(at + 1, 0, false) + 3 + b[at] * 2); // 3
		res = min(res, calc(at + 1, 0, false) + 6); // 4
		res = min(res, calc(at + 1, 6, false) + 18 + b[at] * 2); // 5
		res = min(res, calc(at + 1, 6, true) + 36); // 6
		res = min(res, calc(at + 1, 29, false) + 45 + b[at] * 2); // 7
		res = min(res, calc(at + 1, 29, true) + 90); // 8
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", calc(0, 0, false));
	}
	return 0;
}
