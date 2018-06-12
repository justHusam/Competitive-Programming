#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int dp[1 << 13][25][25];

class CollectingMarbles {
public:
	vector<int> v;
	int n, with, cap;

	int mostMarbles(vector<int> marblesWeights, int bagCapacity, int numberOfBags) {
		n = marblesWeights.size();
		v = marblesWeights;
		with = numberOfBags;
		cap = bagCapacity;
		memset(dp, -1, sizeof dp);
		return calc(0, 0, 0);
	}

	int calc(int mask, int use, int in) {
		if (mask == (1 << n) - 1)
			return 0;
		if (dp[mask][use][in] != -1)
			return dp[mask][use][in];
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (((mask >> i) & 1) == 1)
				continue;
			if (v[i] + in > cap && use + 1 == with)
				continue;
			if (v[i] + in > cap && v[i] <= cap)
				res = max(res, calc(mask | (1 << i), use + 1, v[i]) + 1);
			else if (v[i] <= cap)
				res = max(res, calc(mask | (1 << i), use, v[i] + in) + 1);
		}
		return dp[mask][use][in] = res;
	}
};
