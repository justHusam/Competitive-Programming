#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, a[N], b[N], dp[N][N + 1];

int calc(int at, int with) {
	if (at == n)
		return 0;
	int &res = dp[at][with];
	if (res != -1)
		return res;
	res = calc(at + 1, min(with + b[at], n)) + a[at];
	if (with != 0)
		res = min(res, calc(at + 1, min(with + b[at] - 1, n)) + (a[at] >> 1));
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
