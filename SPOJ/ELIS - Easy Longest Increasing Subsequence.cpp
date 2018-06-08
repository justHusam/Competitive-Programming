#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, dp[15][15];
vector<int> v;

inline int calc(int i, int j) {
	if (i == (int) v.size() - 1)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int res = calc(i + 1, j);
	if (v[i] > v[j])
		res = max(res, calc(i + 1, i) + 1);
	return dp[i][j] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		v.push_back(-2e9);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, n));
	}
	return 0;
}
