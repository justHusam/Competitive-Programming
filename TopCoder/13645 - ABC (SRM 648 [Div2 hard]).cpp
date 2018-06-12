#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int dp[500][31][31][31], n, k;
string res = "";


class ABC {

public:
	string createString(int N, int K) {
		n = N;
		k = K;
		memset(dp, -1, sizeof dp);
		if (calc(0, 0, 0, 0) > 0)
			path(0, 0, 0, 0);
		return res;
	}

	int calc(int w, int i, int a, int b) {
		if (i == n)
			return w == k;
		if (w > k)
			return 0;
		int &res = dp[w][i][a][b];
		if (res != -1)
			return res;
		res = 0;
		res |= calc(w, i + 1, a + 1, b);
		res |= calc(w + a, i + 1, a, b + 1);
		res |= calc(w + a + b, i + 1, a, b);
		return res;
	}

	void path(int w, int i, int a, int b) {
		if (i == n)
			return;
		int x = calc(w, i + 1, a + 1, b);
		int y = calc(w + a, i + 1, a, b + 1);
		int z = calc(w + a + b, i + 1, a, b);
		if (x != 0) {
			res += 'A';
			path(w, i + 1, a + 1, b);
		} else if (y != 0) {
			res += 'B';
			path(w + a, i + 1, a, b + 1);
		} else if (z != 0) {
			res += 'C';
			path(w + a + b, i + 1, a, b);
		}
	}
};
