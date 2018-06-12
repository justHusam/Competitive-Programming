#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class MessageMess {
public:
	string s;
	vector<string> res, v;
	ll dp[50];
	int n;
	string restore(vector<string> dictionary, string message) {
		s = message;
		n = s.length();
		v = dictionary;
		sort(v.begin(), v.end());
		memset(dp, -1, sizeof dp);
		ll r = calc(0);
		if (r == 0)
			return "IMPOSSIBLE!";
		if (r > 1)
			return "AMBIGUOUS!";
		path(0);
		string ss = res[0];
		for (size_t i = 1; i < res.size(); ++i) {
			ss += " ";
			ss += res[i];
		}
		return ss;
	}
	ll calc(int at) {
		if (at == n)
			return 1;
		if (at > n)
			return 0;
		if (dp[at] != -1)
			return dp[at];
		ll res = 0;
		for (int i = 1; i + at <= n; ++i)
			if (binary_search(v.begin(), v.end(), s.substr(at, i)))
				res += calc(at + i);
		return dp[at] = res;
	}
	void path(int at) {
		if (at == n)
			return;
		for (int i = 1; i + at <= n; ++i) {
			string temp = s.substr(at, i);
			if (!binary_search(v.begin(), v.end(), temp))
				continue;
			if (!calc(at + i))
				continue;
			res.push_back(temp);
			path(at + i);
			return;
		}
	}
};

int main(int argc, char **argv) {
	return 0;
}

