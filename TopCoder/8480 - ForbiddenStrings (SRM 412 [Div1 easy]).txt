#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class ForbiddenStrings {
public:
	int nn;
	ll dp[31][335];

	long long countNotForbidden(int n) {
		nn = n;
		memset(dp, -1, sizeof dp);
		return calc(0, 0);
	}

	bool check(int n) {
		bool vis[4] = { };
		int c = 0;
		while (n != 0) {
			int d = n % 10;
			c += vis[d] == 0;
			vis[d] = 1;
			n /= 10;
		}
		return c != 3;
	}

	ll calc(int c, int o) {
		if (c == nn)
			return 1;
		if (dp[c][o] != -1)
			return dp[c][o];
		int oo = o;
		if (oo > 100) {
			int t = oo % 10;
			oo /= 10;
			t = t * 10 + oo % 10;
			oo = t;
		}
		ll res = 0;
		for (int i = 1; i < 4; ++i) {
			int t = oo * 10 + i;
			if (t < 100 || check(t))
				res += calc(c + 1, t);
		}
		return dp[c][o] = res;
	}
};
