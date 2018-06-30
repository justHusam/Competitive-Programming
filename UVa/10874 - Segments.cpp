#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e4;
int n, v[N][2], dp[N][2];

int calc(int i, int p) {
	if (i == n)
		return n - v[n - 1][p];
	int &res = dp[i][p];
	if (res != -1)
		return res;
	res = calc(i + 1, 0) + abs(v[i - 1][p] - v[i][0]) + 2 * (v[i][1] - v[i][0]);
	res = min(res, calc(i + 1, 1) + abs(v[i - 1][p] - v[i][0]) + v[i][1] - v[i][0]);
	res = min(res, calc(i + 1, 0) + abs(v[i - 1][p] - v[i][1]) + v[i][1] - v[i][0]);
	res = min(res, calc(i + 1, 1) + abs(v[i - 1][p] - v[i][1]) + 2 * (v[i][1] - v[i][0]));
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &v[i][0], &v[i][1]);
		memset(dp, -1, sizeof dp);
		int res = calc(1, 0) + v[0][0] - 1 + 2 * (v[0][1] - v[0][0]);
		res = min(res, calc(1, 1) + v[0][0] - 1 + v[0][1] - v[0][0]);
		res += n - 1;
		printf("%d\n", res);
	}
	return 0;
}
