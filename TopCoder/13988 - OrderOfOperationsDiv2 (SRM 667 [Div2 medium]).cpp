#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m, dp[1 << N];
bitset<N> at[N];

int calc(int msk) {
	if (msk == (1 << n) - 1)
		return 0;
	int &res = dp[msk];
	if (res != -1)
		return res;
	res = 2e9;
	bitset<N> on = 0;
	for (int i = 0; i < n; ++i)
		if (((msk >> i) & 1) == 1)
			on.operator |=(at[i]);
	on.flip();
	for (int i = 0; i < n; ++i) {
		if (((msk >> i) & 1) == 1)
			continue;
		bitset<N> bs = on;
		bs.operator &=(at[i]);
		int need = bs.count();
		res = min(res, calc(msk | (1 << i)) + need * need);
	}
	return res;
}

class OrderOfOperationsDiv2 {
public:
	int minTime(vector<string> s) {
		memset(dp, -1, sizeof dp);
		n = s.size();
		m = s[0].size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (s[i][j] == '1')
					at[i][j] = 1;
		return calc(0);
	}
};
