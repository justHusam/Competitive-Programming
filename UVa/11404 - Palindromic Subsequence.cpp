#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3 + 5;
char s[N];
int dp[N][N], n;
vector<vector<string> > p;

int calc(int i, int j) {
	if (i == j)
		return 1;
	if (i - j == 1)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s[i] == s[j])
		return dp[i][j] = calc(i + 1, j - 1) + 2;
	int a = calc(i + 1, j);
	int b = calc(i, j - 1);
	return dp[i][j] = max(a, b);
}

string path(int i, int j) {
	if (i == j) {
		string r = "";
		r += s[i];
		return r;
	}
	if (i - j == 1)
		return "";
	if (p[i][j] != "-1")
		return p[i][j];
	if (s[i] == s[j])
		return p[i][j] = s[i] + path(i + 1, j - 1);;
	int a = calc(i + 1, j);
	int b = calc(i, j - 1);
	if (a > b)
		return p[i][j] = path(i + 1, j);
	if (b > a)
		return p[i][j] = path(i, j - 1);
	string x = path(i + 1, j);
	string y = path(i, j - 1);
	return p[i][j] = min(x, y);
}

string calc() {
	string res = path(0, n - 1);
	int g = calc(0, n - 1);
	if (g == 1)
		return res;
	string temp;
	if ((g & 1) == 1)
		temp = res.substr(0, res.length() - 1);
	else
		temp = res;
	reverse(temp.begin(), temp.end());
	return res + temp;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) != EOF) {
		n = strlen(s);
		memset(dp, -1, sizeof dp);
		calc(0, n - 1);
		p = vector<vector<string> >(n, vector<string>(n, "-1"));
		puts(calc().c_str());
	}
	return 0;
}
