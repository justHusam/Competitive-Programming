#include <bits/stdc++.h>
using namespace std;

vector<string> x, y;
const int N = 1e3;
int dp[N][N];

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
	string f, s;
	int caseN = 1;
	while (getline(cin, f)) {
		getline(cin, s);
		for (size_t i = 0; i < f.size(); ++i)
			if (ispunct(f[i]))
				f[i] = ' ';
		stringstream ss1(f);
		string t;
		x.clear();
		while (ss1 >> t)
			x.push_back(t);
		for (size_t i = 0; i < s.size(); ++i)
			if (ispunct(s[i]))
				s[i] = ' ';
		stringstream ss2(s);
		t.clear();
		y.clear();
		while (ss2 >> t)
			y.push_back(t);
		printf("%2d. ", caseN++);
		if (x.empty() || y.empty()) {
			puts("Blank!");
			continue;
		}
		memset(dp, -1, sizeof dp);
		printf("Length of longest match: %d\n", calc(0, 0));
	}
	return 0;
}
