#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, dp[25];
vector<pair<int, int> > v;

inline int calc(int last) {
	if (dp[last] != -1)
		return dp[last];
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (v[i].first < v[last].first && v[i].second < v[last].second)
			res = max(res, calc(i) + 1);
	return dp[last] = res;
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &v[i].first, &v[i].second);
	memset(dp, -1, sizeof dp);
	v.push_back(make_pair(2e9, 2e9));
	printf("%d\n", calc(n));
	return 0;
}
