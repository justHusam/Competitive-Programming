#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, q, p[6], comb[8][6], dp[1000001], vis[1000001], vs, need[6], Pow[7], cost[8], state[8];

int calc(int msk) {
	if (msk == 0)
		return 0;
	int &res = dp[msk];
	if (vis[msk] == vs)
		return res;
	vis[msk] = vs;
	res = 2e9;
	int at[6], temp = msk;
	for (int i = n - 1; i >= 0; --i) {
		at[i] = temp % 10;
		temp /= 10;
	}
	for (int i = 0; i < n; ++i)
		if (at[i] > 0)
			res = min(res, calc(msk - Pow[n - i - 1]) + p[i]);
	for (int i = 0; i < m; ++i) {
		bool can = true;
		for (int j = 0; j < n && can; ++j)
			can &= at[j] >= comb[i][j];
		if (can)
			res = min(res, calc(msk - state[i]) + cost[i]);
	}
	return res;
}

int main(int argc, char **argv) {
	Pow[0] = 1;
	for (int i = 1; i < 7; ++i)
		Pow[i] = Pow[i - 1] * 10;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &p[i]);
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			state[i] = 0;
			for (int j = 0; j < n; ++j) {
				scanf("%d", &comb[i][j]);
				state[i] = state[i] * 10 + comb[i][j];
			}
			scanf("%d", &cost[i]);
		}
		++vs;
		scanf("%d", &q);
		while (q-- != 0) {
			int msk = 0;
			for (int i = 0; i < n; ++i) {
				scanf("%d", &need[i]);
				msk = msk * 10 + need[i];
			}
			printf("%d\n", calc(msk));
		}
	}
	return 0;
}
