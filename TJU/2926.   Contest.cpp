#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 10;
int n, w, a[3][N], dp[3][301][1 << N];

int calc(int i, int t, int msk) {
	if (i == 3)
		return 0;
	int &res = dp[i][t][msk];
	if (res != -1)
		return res;
	res = calc(i + 1, 0, msk);
	for (int j = 0; j < n; ++j)
		if (((msk >> j) & 1) == 0 && a[i][j] != -1 && t + a[i][j] <= w)
			res = max(res, calc(i, t + a[i][j], msk | (1 << j)) + 1);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &w);
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, 0));
	}
	return 0;
}
