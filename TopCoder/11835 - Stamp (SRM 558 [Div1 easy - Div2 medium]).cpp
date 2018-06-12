#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

class Stamp {
public:
	string s;
	int sc, pc, n, dp[51][4];

	int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
		s = desiredColor;
		n = desiredColor.length(), sc = stampCost, pc = pushCost;
		int res = 2e9;
		for (int l = 1; l <= n; ++l) {
			memset(dp, -1, sizeof dp);
			res = min(res, calc(0, l, 3));
		}
		return res;
	}

	int get(int i, int l) {
		set<int> st;
		for (int j = i; j < i + l; ++j)
			switch (s[j]) {
			case 'R':
				st.insert(0);
				break;
			case 'G':
				st.insert(1);
				break;
			case 'B':
				st.insert(2);
				break;
			}
		if (st.size() > 1)
			return -1;
		if (st.size() == 0)
			return 3;
		return *st.begin();
	}

	bool check(int i, int l, int c) {
		if (i + l > n)
			return 0;
		char col;
		if (c == 0)
			col = 'R';
		if (c == 1)
			col = 'G';
		if (c == 2)
			col = 'B';
		for (int j = i; j < i + l; ++j)
			if (s[j] != '*' && s[j] != col)
				return 0;
		return 1;
	}

	int calc(int i, int l, int c) {
		if (i == n)
			return sc * l;
		if (i > n)
			return 2e9;
		if (dp[i][c] != -1)
			return dp[i][c];
		if (c == 3) {
			int col = get(i, l);
			if (col == -1)
				return dp[i][c] = 2e9;
			if (col != 3)
				return dp[i][c] = calc(i, l, col);
			int res = 2e9;
			for (int j = 0; j < 3; ++j)
				res = min(res, calc(i, l, j));
			return dp[i][c] = res;
		}
		int res = 2e9;
		res = min(res, calc(i + l, l, 3) + pc);
		for (int j = 1; j < l; ++j)
			if (check(i + j, l, c))
				res = min(res, calc(i + j, l, c) + pc);
		return dp[i][c] = res;
	}
};
