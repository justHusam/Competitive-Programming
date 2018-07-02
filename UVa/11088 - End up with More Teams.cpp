#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n, v[15];
vector<bitset<15> > all;
int dp[1 << 15][455], vis[1 << 15][455], id;

void go(int idx, int sum, bitset<15> msk) {
	if (msk.count() == 3) {
		if (sum >= 20)
			all.push_back(msk);
		return;
	}
	if (idx == n)
		return;
	go(idx + 1, sum, msk);
	msk[idx] = 1;
	go(idx + 1, sum + v[idx], msk);
	msk[idx] = 0;
}

int calc(bitset<15> msk, int idx) {
	if (idx == (int) all.size() || n - msk.count() < 3)
		return 0;
	if (vis[msk.to_ulong()][idx] == id)
		return dp[msk.to_ulong()][idx];
	vis[msk.to_ulong()][idx] = id;
	int res = calc(msk, idx + 1);
	if ((msk & all[idx]) == 0)
		res = max(res, calc(msk | all[idx], idx + 1) + 1);
	return dp[msk.to_ulong()][idx] = res;
}

int main(int argc, char **argv) {
	int k = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		all.clear();
		go(0, 0, 0);
		++id;
		printf("Case %d: %d\n", k++, calc(0, 0));
	}
	return 0;
}
