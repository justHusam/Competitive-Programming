#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1005, oo = 1e9;
int n, r, q, nxt[N][10], dp[N][N];
char s[N];
string sol;

int calc(int at, int mod) {
	int &res = dp[at][mod];
	if (res != -1)
		return res;
	res = (mod != r) * -oo;
	for (int i = 0; i < 10; ++i)
		if (nxt[at][i] != n)
			res = max(res, calc(nxt[at][i], (mod * 10 + i) % q) + 1);
	return res;
}

void path(int at, int mod, int len) {
	if (len == 0)
		return;
	int best = calc(at, mod);
	for (int i = 9; i >= 0; --i)
		if (nxt[at][i] != n && calc(nxt[at][i], (mod * 10 + i) % q) + 1 == best) {
			sol += char(i + '0');
			path(nxt[at][i], (mod * 10 + i) % q, len - 1);
			break;
		}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%d%d", s, &r, &q);
		n = strlen(s);
		int at[10] = { };
		for (int i = 0; i < 10; ++i)
			at[i] = n;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 10; ++j)
				nxt[i][j] = at[j];
			at[s[i] - '0'] = i;
		}
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 1; i < 10; ++i)
			if (at[i] != n)
				res = max(res, calc(at[i], i % q) + 1);
		if (res == 0) {
			puts("Not found");
			continue;
		}
		sol.clear();
		for (int i = 9; i > 0; --i)
			if (at[i] != n && calc(at[i], i % q) + 1 == res) {
				sol += char(i + '0');
				path(at[i], i % q, res - 1);
				break;
			}
		puts(sol.c_str());
	}
	return 0;
}
