#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class CuttingBitString {
public:
	string s;
	set<string> st;
	int dp[55][55], N;

	int getmin(string S) {
		s = S;
		N = s.length();
		ll n = 1;
		while (true) {
			string t = bin(n);
			if (t.length() > 50)
				break;
			n *= 5;
			st.insert(t);
		}
		memset(dp, -1, sizeof dp);
		if (st.find(s) != st.end())
			return 1;
		int res = calc(0, 0);
		if (res != 2e9)
			return res;
		return -1;
	}

	string bin(ll n) {
		string s = "";
		while (n > 0) {
			s += (n & 1) + '0';
			n >>= 1;
		}
		reverse(s.begin(), s.end());
		return s;
	}
	int calc(int i, int j) {
		if (i == N)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		int res = 2e9;
		string t = s.substr(j, i - j + 1);
		if (st.find(t) != st.end())
			res = min(res, calc(i + 1, i + 1) + 1);
		if (i != N - 1)
			res = min(res, calc(i + 1, j));
		return dp[i][j] = res;
	}
};
