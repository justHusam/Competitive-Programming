#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class MutaliskEasy {
public:
	map<vector<int>, int> dp;

	int minimalAttacks(vector<int> x) {
		return calc(x);
	}

	int calc(vector<int> v) {
		if (v[0] + v[1] + v[2] == 0)
			return 0;
		map<vector<int>, int>::iterator it = dp.find(v);
		if (it != dp.end())
			return it->second;
		vector<int> p(3);
		int vv[] = { 0, 1, 2 };
		int res = 2e9;
		do {
			p[0] = max(v[vv[0]] - 9, 0);
			p[1] = max(v[vv[1]] - 3, 0);
			p[2] = max(v[vv[2]] - 1, 0);
			res = min(res, calc(p) + 1);
		} while (next_permutation(vv, vv + 3));
		return dp[v] = res;
	}
};
