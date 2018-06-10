#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int dp[1000][2], n;
pair<int, int> v[N];

int calc(int idx, int f) {
	if (idx == n)
		return 0;
	if (dp[idx][f] != -1)
		return dp[idx][f];
	int pre;
	if (f == 1)
		pre = v[idx - 1].second;
	else
		pre = v[idx - 1].first;
	int A = abs(v[idx].first - pre) + v[idx].second + calc(idx + 1, 0);
	int B = abs(v[idx].second - pre) + v[idx].first + calc(idx + 1, 1);
	return dp[idx][f] = max(A, B);
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &v[i].first, &v[i].second);
		memset(dp, -1, sizeof dp);
		int res1 = v[0].first + calc(1, 1);
		memset(dp, -1, sizeof dp);
		int res2 = v[0].second + calc(1, 0);
		printf("%d\n", max(res1, res2));
	}
	return 0;
}
