#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

vector<string> v;
const int N = 101;
int dp[N], n, t;

inline int calc(int idx) {
	if (v[idx] == "LEFT")
		return -1;
	if (v[idx] == "RIGHT")
		return 1;
	if (dp[idx] != -1)
		return dp[idx];
	return dp[idx] = calc(atoi(v[idx].c_str()) - 1);
}

int main(int argc, char **argv) {
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i) {
			char s[50];
			scanf("%s", s);
			if (s[0] == 'S') {
				scanf("%s", s);
				scanf("%s", s);
			}
			v[i] = string(s);
		}
		int res = 0;
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; ++i)
			if (v[i] == "LEFT")
				--res;
			else if (v[i] == "RIGHT")
				++res;
			else
				res += calc(atoi(v[i].c_str()) - 1);
		printf("%d\n", res);
	}
	return 0;
}
