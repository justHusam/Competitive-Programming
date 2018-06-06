#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001;
int n, m, cum[N][N], dp[N][N];
vector<vector<int> > v;

int calc(int i, int j) {
	if (i == n + 1 || j == m + 1)
		return -2e9;
	int &res = dp[i][j];
	if (res != -1)
		return res;
	res = cum[i][j];
	res = max(res, calc(i + 1, j));
	res = max(res, calc(i, j + 1));
	res = max(res, calc(i + 1, j + 1));
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		v.clear();
		v.resize(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &v[i][j]);
		for (int i = 0; i < n; ++i)
			reverse(v[i].begin(), v[i].end());
		reverse(v.begin(), v.end());
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cum[i][j] = v[i - 1][j - 1] + cum[i - 1][j] + cum[i][j - 1] - cum[i - 1][j - 1];
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(1, 1));
	}
	return 0;
}
