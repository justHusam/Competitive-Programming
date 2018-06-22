#include <bits/stdc++.h>
using namespace std;

int n, dp[20][20];
vector<pair<int, int> > x, y;

int calc(int i, int j) {
	if (i == n || j == n)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i].second == y[j].second)
		return dp[i][j] = 1 + calc(i + 1, j + 1);
	int a = calc(i + 1, j);
	int b = calc(i, j + 1);
	return dp[i][j] = max(a, b);
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	x.resize(n);
	y.resize(n);
	for (int i = 0, t; i < n; ++i) {
		scanf("%d", &t);
		x[i] = make_pair(t, i + 1);
	}
	sort(x.begin(), x.end());
	while (scanf("%d", &y[0].first) > 0) {
		y[0].second = 1;
		for (int i = 1, t; i < n; ++i) {
			scanf("%d", &t);
			y[i] = make_pair(t, i + 1);
		}
		sort(y.begin(), y.end());
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
