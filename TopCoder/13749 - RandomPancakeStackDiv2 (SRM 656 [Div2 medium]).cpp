#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class RandomPancakeStackDiv2 {
public:
	double dp[1 << 10][10];
	int vis[1 << 10][10], vs, n;
	vector<int> v;

	double expectedDeliciousness(vector<int> d) {
		n = d.size();
		v = d;
		double res = 0;
		for (int i = 0; i < n; ++i) {
			bitset<10> msk = 0;
			msk[i] = 1;
			++vs;
			double x = calc(msk, i) + v[i];
			res += x * (1.0 / n);
		}
		return res;
	}

	double calc(bitset<10> msk, int last) {
		if ((int) msk.count() == n)
			return 0;
		if (vis[msk.to_ulong()][last] == vs)
			return dp[msk.to_ulong()][last];
		vis[msk.to_ulong()][last] = vs;
		double res = 0;
		for (int i = 0; i < n; ++i)
			if (!msk[i] && i < last) {
				msk[i] = 1;
				res += calc(msk, i) + v[i];
				msk[i] = 0;
			}
		return dp[msk.to_ulong()][last] = res / (n - msk.count());
	}
};
