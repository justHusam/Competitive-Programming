#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class ChristmasTreeDecorationDiv2 {
public:
	int solve(vector<int> col, vector<int> x, vector<int> y) {
		int res = 0;
		for (size_t a = 0; a < x.size(); ++a)
			res += col[x[a] - 1] != col[y[a] - 1];
		return res;
	}

};
