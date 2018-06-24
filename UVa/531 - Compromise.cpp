#include <bits/stdc++.h>
using namespace std;

vector<string> x, y, res;
const int N = 101;
short dp[N][N];
char s[350];

int calc(size_t i, size_t j) {
	if (i == x.size() || j == y.size())
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = calc(i + 1, j + 1) + 1;
	int a = calc(i + 1, j);
	int b = calc(i, j + 1);
	return dp[i][j] = max(a, b);
}

void path(size_t i, size_t j) {
	if (i == x.size() || j == y.size())
		return;
	if (x[i] == y[j]) {
		res.push_back(x[i]);
		path(i + 1, j + 1);
		return;
	}
	int a = calc(i + 1, j);
	int b = calc(i, j + 1);
	if (a > b)
		path(i + 1, j);
	else
		path(i, j + 1);
}

int main(int argc, char **argv) {
	while (gets(s) > 0) {
		x.clear();
		y.clear();
		do {
			for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "))
				x.push_back(string(z));
		} while (gets(s) && s[0] != '#');
		while (gets(s) && s[0] != '#')
			for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "))
				y.push_back(string(z));
		memset(dp, -1, sizeof dp);
		calc(0, 0);
		res.clear();
		path(0, 0);
		if (res.size())
			printf("%s", res[0].c_str());
		for (size_t i = 1; i < res.size(); ++i)
			printf(" %s", res[i].c_str());
		putchar('\n');
	}
	return 0;
}
