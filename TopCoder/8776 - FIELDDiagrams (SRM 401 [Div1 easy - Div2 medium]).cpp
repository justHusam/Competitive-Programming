#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class FIELDDiagrams {
public:
	ll dp[31][31];
	int n;
	long long countDiagrams(int fieldOrder) {
		n = fieldOrder;
		memset(dp, -1, sizeof dp);
		ll res = 0;
		for (int i = n; i > 0; --i)
			res += calc(n, i);
		return res;
	}

	ll calc(int r, int m) {
		if (m > r)
			return 0;
		if (r == 1)
			return 1;
		if (dp[r][m] != -1)
			return dp[r][m];
		ll res = 0;
		for (int i = m; i >= 0; --i)
			res += calc(r - 1, i);
		return dp[r][m] = res;
	}
};
