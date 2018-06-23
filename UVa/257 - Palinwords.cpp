#include <bits/stdc++.h>
using namespace std;

const int N = 256;
int n, DP[N][N], cum[N], dp[N][N];
char s[N];
set<string> st[N];

int check(int l, int r) {
	if (l >= r)
		return 1;
	int &res = DP[l][r];
	if (res != -1)
		return res;
	res = 0;
	if (s[l] == s[r])
		res = check(l + 1, r - 1);
	return res;
}

int calc(int l, int r) {
	if (r - l < 2)
		return 0;
	int &res = dp[l][r];
	if (res != -1)
		return res;
	res = 0;
	if (check(l, r))
		++res;
	res += calc(l + 1, r);
	res += calc(l, r - 1);
	res -= calc(l + 1, r - 1);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) != EOF) {
		n = strlen(s);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dp[i][j] = DP[i][j] = -1;
		for (int i = 3; i <= n; ++i)
			st[i].clear();
		for (int i = 0; i < n; ++i) {
			string w = "";
			for (int j = i; j < n; ++j) {
				w += s[j];
				if (w.size() >= 3 && check(i, j))
					st[j - i + 1].insert(w);
			}
		}
		for (int i = 3; i <= n; ++i)
			cum[i] = cum[i - 1] + st[i].size();
		bool can = false;
		for (int i = 0; i < n && !can; ++i)
			for (int j = i + 2; j < n && !can; ++j)
				if (check(i, j)) {
					int len = j - i + 1;
					int sz = cum[len] - calc(i, j);
					if (sz >= 1)
						can = true;
				}
		if (can)
			puts(s);
	}
	return 0;
}
