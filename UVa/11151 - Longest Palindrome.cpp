#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3 + 9;
char s[N];
vector<vector<int> > dp;

int calc(int i, int j) {
	if (i == j)
		return 1;
	if (i > j)
		return 0;
	int &res = dp[i][j];
	if (res != -1)
		return res;
	if (s[i] == s[j])
		return res = calc(i + 1, j - 1) + 2;
	return res = max(calc(i + 1, j), calc(i, j - 1));
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	gets(s);
	while (T-- != 0) {
		gets(s);
		int n = strlen(s);
		dp = vector<vector<int> >(n + 1, vector<int>(n + 1, -1));
		printf("%d\n", calc(0, n - 1));
	}
	return 0;
}
