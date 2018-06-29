#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e3;
int dp[N][26], k, n, cnt[N][26], add[N], all;
char s[N + 9];

int calc(int at, int l) {
	if (at == all)
		return 0;
	if (dp[at][l] != -1)
		return dp[at][l];
	int res = 2e9, M = cnt[at][l] ? 1 : 0;
	for (int i = 0; i < 26; ++i)
		if (cnt[at][i]) {
			if (add[at] > 1 && i == l)
				continue;
			res = min(res, calc(at + 1, i) + add[at] - M);
		}
	return dp[at][l] = res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%s", &k, s);
		n = strlen(s);
		memset(cnt, 0, sizeof cnt);
		memset(add, 0, sizeof add);
		for (int i = 0, I = 0; i < n; i += k, ++I) {
			for (int j = i; j < i + k; ++j)
				++cnt[I][s[j] - 'a'];
			for (int j = 0; j < 26; ++j)
				if (cnt[I][j] != 0)
					++add[I];
		}
		memset(dp, -1, sizeof dp);
		int res = 2e9;
		all = n / k;
		for (int i = 0; i < 26; ++i)
			if (cnt[0][i] != 0)
				res = min(res, calc(1, i) + add[0]);
		printf("%d\n", res);
	}
	return 0;
}
