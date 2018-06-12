#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

class NumberofFiboCalls {
public:
	pair<int, int> dp[45];
	vector<int> fiboCallsMade(int n) {
		memset(dp, -1, sizeof dp);
		pair<int, int> res = calc(n);
		vector<int> v;
		v.push_back(res.first);
		v.push_back(res.second);
		return v;
	}
	pair<int, int> calc(int n) {
		if (n == 1)
			return make_pair(0, 1);
		if (n == 0)
			return make_pair(1, 0);
		if (dp[n] != make_pair(-1, -1))
			return dp[n];
		pair<int, int> a = calc(n - 1), b = calc(n - 2);
		return dp[n] = make_pair(a.first + b.first, a.second + b.second);
	}
};
