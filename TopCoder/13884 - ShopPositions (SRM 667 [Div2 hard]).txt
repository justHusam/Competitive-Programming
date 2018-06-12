#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 31;
int n, m, dp[N][N][N];
vector<int> v;

int calc(int at, int before, int in) {
	if (at == n)
		return 0;
	int &res = dp[at][before][in];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 0; i <= m; ++i) {
		int y = before + in + i;
		if (y == 0)
			res = max(res, calc(at + 1, in, i));
		else
			res = max(res, calc(at + 1, in, i) + v[at * 3 * m + y - 1] * in);
	}
	return res;
}

class ShopPositions {
public:
	int maxProfit(int n, int m, vector<int> c) {
		memset(dp, -1, sizeof dp);
		::n = n;
		::m = m;
		v = c;
		int res = 0;
		for (int i = 0; i <= m; ++i)
			res = max(res, calc(0, 0, i));
		return res;
	}
};
