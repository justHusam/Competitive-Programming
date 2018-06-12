#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int fact[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };

class Lottery {
public:
	int n, b;
	ll dp[10][102];
	vector<string> sortByOdds(vector<string> rules) {
		vector<pair<ll, string> > temp;
		for (size_t i = 0; i < rules.size(); ++i) {
			string nm = "";
			int c = 0;
			for (c = 0; rules[i][c] != ':'; ++c)
				nm += rules[i][c];
			stringstream ss(rules[i].substr(c + 2));
			char s, u;
			ss >> n >> b >> s >> u;
			if (s == 'F' && u == 'F') {
				temp.push_back(make_pair(calc(), nm));
				continue;
			}
			memset(dp, -1, sizeof dp);
			if (s == 'F' && u == 'T')
				temp.push_back(make_pair(calc(0, 0), nm));
			if (s == 'T' && u == 'T')
				temp.push_back(make_pair(calc(0, 0, 1), nm));
			if (s == 'T' && u == 'F')
				temp.push_back(make_pair(calc(0, 1, 0), nm));
		}
		sort(temp.begin(), temp.end());
		vector<string> res;
		for (size_t i = 0; i < temp.size(); ++i)
			res.push_back(temp[i].second);
		return res;
	}
	// T T --> f=1 and T F --> f=0
	ll calc(int c, int m, int f) {
		if (c == b)
			return 1;
		if (dp[c][m] != -1)
			return dp[c][m];
		ll res = 0;
		for (int a = m + f; a <= n; ++a)
			res += calc(c + 1, a, f);
		return dp[c][m] = res;
	}
	// F F
	ll calc() {
		return pow(n, b);
	}
	// F T
	ll calc(int c, int i) {
		if (c == b)
			return fact[b];
		if (i == n)
			return 0;
		if (dp[c][i] != -1)
			return dp[c][i];
		return dp[c][i] = calc(c, i + 1) + calc(c + 1, i + 1);
	}
};

int main(int argc, char **argv) {
	return 0;
}
