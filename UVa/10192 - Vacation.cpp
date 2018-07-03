#include <bits/stdc++.h>
using namespace std;

string x, y;
int dp[100][100];

int calc(size_t i, size_t j) {
	if (i == x.size() || j == y.size())
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = 1 + calc(i + 1, j + 1);
	int a = calc(i + 1, j);
	int b = calc(i, j + 1);
	return dp[i][j] = max(a, b);
}

int main(int argc, char **argv) {
	int k = 1;
	while (getline(cin, x) && x[0] != '#') {
		getline(cin, y);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: you can visit at most %d cities.\n", k++, calc(0, 0));
	}
	return 0;
}
