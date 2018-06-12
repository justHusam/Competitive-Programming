#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class HillHike {
public:
	ll dp[101][51][101][2];
	int n, m;
	vector<int> v;
	long long numPaths(int distance, int maxHeight, vector<int> landmarks) {
		n = distance;
		m = maxHeight;
		v = landmarks;
		memset(dp, -1, sizeof dp);
		return calc(0, 0, 0, 0);
	}
	ll calc(int d, int h, int i, int f) {
		if (d == n)
			return !h && f && i == (int) v.size();
		if (h < 0 || h > m || (d && !h))
			return 0;
		if (dp[d][h][i][f] != -1)
			return dp[d][h][i][f];
		ll res = 0;
		int ii = i < (int) v.size() && h == v[i];
		for (int a = -1; a <= 1; ++a)
			res += calc(d + 1, h + a, i + ii, f || (h == m));
		return dp[d][h][i][f] = res;
	}
};

int main(int argc, char **argv) {
	return 0;
}

