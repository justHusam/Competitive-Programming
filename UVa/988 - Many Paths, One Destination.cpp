#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n;
vector<vector<int> > g;
vector<int> dp;

inline int calc(int idx) {
	if (!g[idx].size())
		return 1;
	if (dp[idx] != -1)
		return dp[idx];
	int res = 0;
	for (size_t i = 0; i < g[idx].size(); ++i)
		res += calc(g[idx][i]);
	return dp[idx] = res;
}

int main(int argc, char **argv) {
	bool newLine = false;
	while (scanf("%d", &n) > 0) {
		if (newLine)
			puts("");
		newLine = true;
		g.clear();
		g.resize(n + 1);
		for (int i = 0, x, u; i < n; ++i) {
			scanf("%d", &x);
			while (x-- != 0) {
				scanf("%d", &u);
				g[i].push_back(u);
			}
		}
		dp.clear();
		dp.resize(n + 1, -1);
		printf("%d\n", calc(0));
	}
	return 0;
}
