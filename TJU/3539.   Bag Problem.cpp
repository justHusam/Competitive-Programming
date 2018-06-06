#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k, v[40];
map<int, int> dp[40][40];

int calc(int i, int c, int w) {
	if (i == k || c == n)
		return w;
	if (dp[i][c].find(w) != dp[i][c].end())
		return dp[i][c][w];
	int res = calc(i + 1, c, w);
	if (w - v[i] >= 0)
		res = min(res, calc(i + 1, c + 1, w - v[i]));
	return dp[i][c][w] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &m, &k) > 0) {
		for (int i = 0; i < k; ++i)
			scanf("%d", &v[i]);
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < n; ++j)
				dp[i][j].clear();
		printf("%d\n", m - calc(0, 0, m));
	}
	return 0;
}
