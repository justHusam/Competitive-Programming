#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class InfiniteSequence {
public:
	map<ll, ll> dp;
	ll x, y;

	long long calc(long long n, int p, int q) {
		x = p;
		y = q;
		return _calc(n);
	}

	ll _calc(ll n) {
		if (!n)
			return 1;
		if (dp.find(n) != dp.end())
			return dp[n];
		return dp[n] = _calc(n / x) + _calc(n / y);
	}
};
