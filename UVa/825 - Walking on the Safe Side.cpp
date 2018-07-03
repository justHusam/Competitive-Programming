#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int R, C;
vector<vector<bool> > g;
vector<vector<int> > dp;

int calc(int i, int j) {
	if (i >= R || j >= C || g[i][j])
		return 0;
	if (i == R - 1 && j == C - 1)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = calc(i + 1, j) + calc(i, j + 1);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &R, &C);
		g.clear();
		g.resize(R, vector<bool>(C, false));
		string s;
		cin.ignore();
		for (int i = 0; i < R; ++i) {
			getline(cin, s);
			stringstream ss(s);
			int x, y;
			ss >> x;
			--x;
			while (ss >> y) {
				--y;
				g[x][y] = true;
			}
		}
		dp.clear();
		dp.resize(R, vector<int>(C, -1));
		printf("%d\n", calc(0, 0));
		if (T != 0)
			puts("");
	}
	return 0;
}
