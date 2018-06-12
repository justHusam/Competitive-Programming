#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class MaximalProduct {
public:
	ll dp[110][22];
	int kk;
	long long maximalProduct(int s, int k) {
		kk = k;
		memset(dp, -1, sizeof dp);
		return calc(s, 0);
	}
	ll calc(int r, int i) {
		if (i == kk)
			return !r;
		if (dp[r][i] != -1)
			return dp[r][i];
		ll res = 0;
		for (ll a = r; a > 0; --a)
			res = max(res, a * calc(r - a, i + 1));
		return dp[r][i] = res;
	}
};
