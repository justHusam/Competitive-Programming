#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

map<pair<int, int>, int> dp[1001][2];

class TheNumberGame {
public:
	string determineOutcome(int A, int B) {
		int a[10] = { }, b[10] = { }, TA = A, TB = B, c = 0;
		while (TA > 0) {
			a[TA % 10] = 1;
			TA /= 10;
		}
		while (TB > 0) {
			b[TB % 10] = 1;
			TB /= 10;
		}
		for (int i = 0; i < 10; ++i)
			c += a[i] && b[i];
		if (c == 0 || calc(0, 0, A, B) == 0)
			return "Manao loses";
		return "Manao wins";
	}

	inline int get(int n) {
		int m = 0;
		while (n != 0) {
			m *= 10;
			m += n % 10;
			n /= 10;
		}
		return m;
	}

	int calc(int cnt, int tr, int a, int b) {
		if (cnt > 1000)
			return 0;
		if (a == b)
			return 1;
		if (dp[cnt][tr].find(make_pair(a, b)) != dp[cnt][tr].end())
			return dp[cnt][tr][make_pair(a, b)];
		if (a < 10 && b < 10)
			return 0;
		if (tr == 0) {
			int res = 0;
			res = max(res, calc(cnt + 1, 1, get(a), b));
			res = max(res, calc(cnt + 1, 1, a / 10, b));
			return dp[cnt][tr][make_pair(a, b)] = res;
		}
		return dp[cnt][tr][make_pair(a, b)] = calc(cnt + 1, 0, a, get(b));
	}
};
