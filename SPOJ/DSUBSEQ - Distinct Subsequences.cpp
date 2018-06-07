#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1, M = 1e9 + 7;
int n, nxt[N][26], dp[N];
char s[N];

int calc(int at) {
	int &res = dp[at];
	if (res != -1)
		return res;
	res = 1;
	for (int i = 0; i < 26; ++i)
		if (nxt[at][i] != -1) {
			res += calc(nxt[at][i]);
			if (res >= M)
				res -= M;
		}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		n = strlen(s);
		int at[26] = { };
		memset(at, -1, sizeof at);
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 26; ++j)
				nxt[i][j] = at[j];
			at[s[i] - 'A'] = i;
		}
		for (int i = 0; i < n; ++i)
			dp[i] = -1;
		int res = 1;
		for (int i = 0; i < 26; ++i)
			if (at[i] != -1) {
				res += calc(at[i]);
				if (res >= M)
					res -= M;
			}
		printf("%d\n", res);
	}
	return 0;
}
