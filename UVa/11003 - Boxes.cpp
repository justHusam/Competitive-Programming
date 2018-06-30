#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e3;
int n, a[N], b[N], dp[N][3 * N + 1];

int calc(int i, int w) {
	if (i == n)
		return 0;
	int &res = dp[i][w];
	if (res != -1)
		return res;
	res = calc(i + 1, w);
	if (a[i] <= w)
		res = max(res, calc(i + 1, min(w - a[i], b[i])) + 1);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", a + i, b + i);
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < n; ++i)
			res = max(res, calc(i + 1, b[i]) + 1);
		printf("%d\n", res);
	}
	return 0;
}