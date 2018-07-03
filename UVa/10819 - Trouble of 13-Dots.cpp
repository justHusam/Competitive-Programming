#include <bits/stdc++.h>
using namespace std;

int n, m;
short dp[10201][100];
pair<int, int> v[100];

int calc(int r, int i, int m, bool f) {
	if (r > m)
		return -2e9;
	if (i == n)
		return 0;
	if (dp[r][i] != -1)
		return dp[r][i];
	int res = calc(r, i + 1, m, f);
	if (v[i].first + r > 2000 && !f)
		res = max(res, calc(r + v[i].first, i + 1, m + 200, true) + v[i].second);
	else
		res = max(res, calc(r + v[i].first, i + 1, m, f) + v[i].second);
	return dp[r][i] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &m, &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &v[i].first, &v[i].second);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, m, false));
	}
	return 0;
}
