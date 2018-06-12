#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class BadSubstring {
public:
	ll dp[45][4];
	int n;
	ll howMany(int length) {
		n = length;
		memset(dp, -1, sizeof dp);
		return calc(0, 3);
	}
	ll calc(int cnt, int ch) {
		if (cnt == n)
			return 1;
		if (dp[cnt][ch] != -1)
			return dp[cnt][ch];
		// a = 0 , b = 1 , c = 2;
		ll res = 0;
		res += calc(cnt + 1, 0);
		res += calc(cnt + 1, 2);
		if (ch != 0)
			res += calc(cnt + 1, 1);
		return dp[cnt][ch] = res;
	}
};

int main(int argc, char **argv) {
	return 0;
}
