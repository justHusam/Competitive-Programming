#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

class MatchNumbersEasy {
public:
	vector<int> v;
	string dp[51][10];
	string A[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	string maxNumber(vector<int> matches, int n) {
		v = matches;
		for (int i = 0; i < 51; ++i)
			for (int j = 0; j < 10; ++j)
				dp[i][j] = "-1";
		string res = "0";
		for (size_t i = 1; i < v.size(); ++i)
			res = comp(res, calc(n - v[i], A[i]));
		return res;
	}

	string comp(const string &s, const string &ss) {
		int n = s.length(), m = ss.length();
		if (s[0] == '-' && ss[0] == '-')
			return "";
		if (ss[0] == '-')
			return s;
		if (s[0] == '-')
			return ss;
		if (n < m)
			return ss;
		if (n > m)
			return s;
		if (s[0] == '-')
			return ss;
		for (int i = 0; i < n; ++i) {
			if (s[i] == ss[i])
				continue;
			if (s[i] > ss[i])
				return s;
			return ss;
		}
		return "";
	}

	string calc(int r, string s) {
		if (r < 0)
			return "-2";
		if (dp[r][s[0] - '0'] != "-1")
			return dp[r][s[0] - '0'];
		string res = "";
		for (size_t i = 0; i < v.size(); ++i)
			res = comp(res, calc(r - v[i], A[i]));
		return dp[r][s[0] - '0'] = s + res;
	}
};
