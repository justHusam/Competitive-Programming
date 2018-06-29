#include<bits/stdc++.h>
using namespace std;

const int N = 100, oo = 2e9;
int n, dp[N][2][2];
char s[N + 9];

int calc(int i, bool b, bool m) {
	if (i == n)
		return (!b && s[n - 1] != '#') * oo;
	int &res = dp[i][b][m];
	if (res != -1)
		return res;
	res = oo;
	if (i == 0 || b || (i != 0 && s[i - 1] == '#'))
		res = min(res, calc(i + 1, m, false));
	res = min(res, calc(i + 1, true, true) + 1);
	return res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%s", &n, s);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", k++, calc(0, false, false));
	}
	return 0;
}
