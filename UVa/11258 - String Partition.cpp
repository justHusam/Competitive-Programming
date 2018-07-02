#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n;
ll dp[200][12];
char s[210];

ll get(int at, int len) {
	if (len > 1 && s[at] == '0')
		return 0;
	ll res = 0;
	for (int i = at, j = 0; j < len; ++i, ++j)
		res = res * 10 + (s[i] - '0');
	if (res <= INT_MAX)
		return res;
	return -1;
}

ll calc(int at, int len) {
	if (at == n)
		return 0;
	if (dp[at][len] != -1)
		return dp[at][len];
	ll res = -(2e15);
	if (len + 1 <= 10 && at + len < n)
		res = max(res, calc(at, len + 1));
	ll g = get(at, len);
	if (g != -1)
		res = max(res, calc(at + len, 1) + g);
	return dp[at][len] = res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		n = strlen(s);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", calc(0, 1));
	}
	return 0;
}
