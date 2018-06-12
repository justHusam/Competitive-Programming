#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class TaroFillingAStringDiv2 {
public:
	string s;
	int n, dp[50][3];

	int getNumber(string S) {
		s = S;
		n = S.size();
		memset(dp, -1, sizeof dp);
		return calc(0, 2);
	}

	int calc(int i, int p) {
		if (i == n)
			return 0;
		int &res = dp[i][p];
		if (res != -1)
			return res;
		res = 2e9;
		if (s[i] != '?')
			return res = calc(i + 1, s[i] - 'A') + (s[i] - 'A' == p);
		res = min(res, calc(i + 1, 0) + (p == 0));
		res = min(res, calc(i + 1, 1) + (p == 1));
		return res;
	}
};
