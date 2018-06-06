#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 5e3 + 9;
char s[N];
ll dp[N];
int n;

bool check(int idx) {
	if (idx + 1 >= n)
		return false;
	if (s[idx] == '1')
		return true;
	if (s[idx] == '2' && s[idx + 1] <= '6')
		return true;
	return false;
}

ll calc(int idx) {
	if (idx == n)
		return 1;
	if (idx > n)
		return 0;
	if (s[idx] == '0')
		return dp[idx] = 0;
	if (dp[idx] != -1)
		return dp[idx];
	ll res = 0;
	res += calc(idx + 1);
	if (check(idx))
		res += calc(idx + 2);
	return dp[idx] = res;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) && s[0] != '0') {
		n = strlen(s);
		memset(dp, -1, sizeof dp);
		cout << calc(0) << "\n";
	}
	return 0;
}
