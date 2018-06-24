#include <bits/stdc++.h>
using namespace std;

vector<int> v, res;
vector<vector<int> > dp;
int n;

inline int calc(int i, int j) {
	if (i == n - 1)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int res = calc(i + 1, j);
	if (v[i] > v[j])
		res = max(res, calc(i + 1, i) + 1);
	return dp[i][j] = res;
}

inline void path(int i, int j) {
	if (i == n - 1)
		return;
	int a = calc(i + 1, j), b = -1;
	if (v[i] > v[j])
		b = calc(i + 1, i) + 1;
	if (a > b) {
		path(i + 1, j);
		return;
	}
	res.push_back(v[i]);
	path(i + 1, i);
}

int main(int argc, char **argv) {
	int T;
	bool newLine = false;
	scanf("%d\n", &T);
	while (T-- != 0) {
		if (newLine)
			puts("");
		newLine = true;
		char s[20];
		v.clear();
		int mn = INT_MAX;
		while (gets(s) > 0 && strlen(s) != 0) {
			int x = atoi(s);
			v.push_back(x);
			mn = min(x, mn);
		}
		v.push_back(mn - 1);
		n = v.size();
		dp.clear();
		dp.resize(n, vector<int>(n, -1));
		printf("Max hits: %d\n", calc(0, n - 1));
		res.clear();
		path(0, n - 1);
		for (size_t i = 0; i < res.size(); ++i)
			printf("%d\n", res[i]);
	}
	return 0;
}
