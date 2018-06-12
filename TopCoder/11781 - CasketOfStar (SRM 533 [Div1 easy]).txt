#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

class CasketOfStar {
public:
	vector<int> g;
	int dp[50][50], n;

	int maxEnergy(vector<int> weight) {
		g = weight;
		memset(dp, -1, sizeof dp);
		n = g.size();
		return calc(0, n - 1);
	}

	int calc(int i, int j) {
		if (i >= n - 1 || j <= 0)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		int res = 0;
		for (int k = i + 1; k < j; ++k)
			res = max(res, calc(i, k) + calc(k, j) + g[i] * g[j]);
		return dp[i][j] = res;
	}
};

