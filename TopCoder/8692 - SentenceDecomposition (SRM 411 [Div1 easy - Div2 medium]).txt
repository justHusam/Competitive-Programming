#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

class SentenceDecomposition {
public:
	string s;
	vector<string> v;
	int dp[50], n;

	int decompose(string sentence, vector<string> validWords) {
		s = sentence;
		n = s.size();
		v = validWords;
		memset(dp, -1, sizeof dp);
		int res = calc(0);
		if (res != 2e9)
			return res;
		return -1;
	}

	int get(string s) {
		string srt = s;
		sort(srt.begin(), srt.end());
		int res = 2e9;
		for (size_t i = 0; i < v.size(); ++i) {
			if (v[i].size() != s.size())
				continue;
			string temp = v[i];
			sort(temp.begin(), temp.end());
			if (temp != srt)
				continue;
			int r = 0;
			for (size_t j = 0; j < s.size(); ++j)
				r += s[j] != v[i][j];
			res = min(res, r);
		}
		return res;
	}

	int calc(int at) {
		if (at == n)
			return 0;
		if (at > n)
			return 2e9;
		if (dp[at] != -1)
			return dp[at];
		int res = 2e9;
		for (int i = 1; i + at <= n; ++i) {
			int r = get(s.substr(at, i));
			if (r != 2e9)
				res = min(res, calc(at + i) + r);
		}
		return dp[at] = res;
	}
};
