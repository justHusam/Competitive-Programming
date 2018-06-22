#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int> > dp;
int n;

int calc(int i, int p) {
	if (i == n - 1)
		return 0;
	if (dp[i][p] != -1)
		return dp[i][p];
	int res = calc(i + 1, p);
	if (v[i] <= v[p])
		res = max(res, calc(i + 1, i) + 1);
	return dp[i][p] = res;
}

int main(int argc, char **argv) {
	int x, k = 1;
	bool newLine = false;
	while (scanf("%d", &x) && x != -1) {
		if (newLine)
			puts("");
		newLine = true;
		v.clear();
		v.push_back(x);
		while (scanf("%d", &x) && x != -1)
			v.push_back(x);
		v.push_back(1e9);
		n = v.size();
		dp.clear();
		dp.resize(n, vector<int>(n, -1));
		printf("Test #%d:\n  maximum possible interceptions: %d\n", k++, calc(0, n - 1));
	}
	return 0;
}
