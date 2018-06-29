#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

vector<int> v, vv;
vector<vector<int> > dp;
int n, t, k;

int calc(int idx, int pre, int f) {
	if (idx == n - 2)
		return 0;
	if (dp[idx][pre] != -1)
		return dp[idx][pre];
	int res = calc(idx + 1, pre, f);
	if (f != 0 && v[idx] > v[pre])
		res = max(res, calc(idx + 1, idx, f) + vv[idx]);
	if (f == 0 && v[idx] < v[pre])
		res = max(res, calc(idx + 1, idx, f) + vv[idx]);
	return dp[idx][pre] = res;
}

int main(int argc, char **argv) {
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		v.clear();
		v.resize(n);
		vv.clear();
		vv.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &vv[i]);
		n += 2;
		v.push_back(-1);
		v.push_back(2e9);
		dp = vector<vector<int> >(n, vector<int>(n, -1));
		int r1 = calc(0, n - 2, 1);
		dp = vector<vector<int> >(n, vector<int>(n, -1));
		int r2 = calc(0, n - 1, 0);
		printf("Case %d. ", ++k);
		if (r1 >= r2)
			printf("Increasing (%d). Decreasing (%d).\n", r1, r2);
		else
			printf("Decreasing (%d). Increasing (%d).\n", r2, r1);
	}
	return 0;
}
