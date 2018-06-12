#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */


class MarblesRegroupingHard {
public:
	int n, m, dp[51][1 << 14];
	vector<vector<int> > g;
	int minMoves(vector<string> boxes) {
		n = boxes.size();
		g.resize(n);
		for (int i = 0; i < n; ++i) {
			stringstream ss(boxes[i]);
			int x;
			while (ss >> x)
				g[i].push_back(x);
		}
		m = g[0].size();
		memset(dp, -1, sizeof dp);
		return calc(0, 0);
	}

	int calc(int at, int msk) {
		if (msk == (1 << m) - 1)
			return 0;
		if (at == n)
			return 2e9;
		if (dp[at][msk] != -1)
			return dp[at][msk];
		int res = 2e9;
		for (int i = 0; i < m; ++i) {
			if (((msk >> i) & 1) == 1)
				continue;
			int temp = 0;
			for (int j = 0; j < n; ++j)
				if (j != at)
					temp += g[j][i];
			res = min(res, temp + calc(at + 1, msk | (1 << i)));
		}
		return dp[at][msk] = min(res, calc(at + 1, msk));
	}
};
