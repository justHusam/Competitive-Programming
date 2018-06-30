#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[20];
int n, row[15];
ll dp[17][17];

ll calc(int r, int c) {
	if (c == n)
		return 1;
	ll &res = dp[r][c];
	if (res != -1)
		return res;
	res = 0;
	if (row[c] != -1)
		return res = calc(row[c], c + 1);
	if (c + 1 != n && row[c + 1] != -1) {
		for (int i = 0; i < n; ++i)
			if (abs(i - r) > 1 && abs(i - row[c + 1]) > 1)
				res += calc(i, c + 1);
	} else {
		for (int i = 0; i < n; ++i)
			if (abs(i - r) > 1)
				res += calc(i, c + 1);
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0) {
		n = strlen(s);
		for (int i = 0; i < n; ++i)
			if (s[i] == '?')
				row[i] = -1;
			else if (isdigit(s[i]))
				row[i] = s[i] - '0' - 1;
			else
				row[i] = s[i] - 'A' + 9;
		memset(dp, -1, sizeof dp);
		ll res = -1;
		for (int i = 1; i < n; ++i)
			if (row[i] != -1 && row[i - 1] != -1 && abs(row[i] - row[i - 1]) <= 1)
				res = 0;
		if (res == -1)
			res = calc(16, 0);
		printf("%lld\n", res);
	}
	return 0;
}
