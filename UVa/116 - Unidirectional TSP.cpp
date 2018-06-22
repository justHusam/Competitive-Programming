#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int r, c, g[10][100], dp[10][100];
vector<int> v;

int calc(int i, int j) {
	if (i < 0)
		i = r - 1;
	if (i == r)
		i = 0;
	if (j == c)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int a = calc(i - 1, j + 1);
	int b = calc(i, j + 1);
	int c = calc(i + 1, j + 1);
	return dp[i][j] = g[i][j] + min(a, min(b, c));
}

int get(int i1, int i2, int i3, int j) {
	int c1 = dp[i1][j], c2 = dp[i2][j], c3 = dp[i3][j], mn = min(c1, min(c2, c3)), cnt = 0;
	cnt += c1 == mn;
	cnt += c2 == mn;
	cnt += c3 == mn;
	if (cnt == 3)
		return min(i1, min(i2, i3));
	if (cnt == 2) {
		if (c1 == mn && c2 == mn)
			return min(i1, i2);
		if (c1 == mn && c3 == mn)
			return min(i1, i3);
		if (c2 == mn && c3 == mn)
			return min(i2, i3);
	}
	if (c1 == mn)
		return i1;
	if (c2 == mn)
		return i2;
	return i3;
}

void path(int i, int j) {
	v.push_back(i);
	if (j + 1 == c)
		return;
	int i1 = i - 1, i2 = i, i3 = i + 1;
	if (i1 < 0)
		i1 = r - 1;
	if (i3 == r)
		i3 = 0;
	int ir = get(i1, i2, i3, j + 1);
	path(ir, j + 1);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &r, &c) > 0) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				scanf("%d", &g[i][j]);
		int res = 2e9, at;
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < r; ++i) {
			int temp = calc(i, 0);
			if (temp < res) {
				res = temp;
				at = i;
			}
		}
		v.clear();
		path(at, 0);
		string s = "";
		for (size_t i = 0; i < v.size(); ++i, s = " ")
			printf("%s%d", s.c_str(), v[i] + 1);
		printf("\n%d\n", res);
	}
	return 0;
}
