#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500000;
int n, k, dp[N][26];
char s[N + 1];

int calc(int at, int p) {
	if (at == n)
		return 0;
	int &res = dp[at][p];
	if (res != -1)
		return res;
	res = 2e9;
	if (s[at] - 'A' != p)
		res = min(res, calc(at + 1, s[at] - 'A'));
	for (int i = 0; i < k; ++i)
		if (i != p)
			res = min(res, calc(at + 1, i) + 1);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%s", &n, &k, s);
		memset(dp, -1, sizeof dp);
		int res = calc(1, s[0] - 'A');
		for (int i = 0; i < k; ++i)
			res = min(res, calc(1, k) + 1);
		printf("%d\n", res);
	}
	return 0;
}
